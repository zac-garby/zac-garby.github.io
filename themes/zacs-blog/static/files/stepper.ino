const int stepsPerRevolution = 2048;

class Stepper {
public:
  int p1, p2, p3, p4;
  unsigned int currentStep;
  unsigned long lastStepTime, stepDelay;
  unsigned long numSteps;
  int direction;
  bool stopped;

  Stepper(int p1, int p2, int p3, int p4, int direction) {
    this->currentStep = 0;
    this->direction = direction;
    this->lastStepTime = 0;
    this->numSteps = 2048;
    this->stepDelay = 4000;
    this->stopped = false;

    this->p1 = p1;
    this->p2 = p2;
    this->p3 = p3;
    this->p4 = p4;

    pinMode(p1, OUTPUT);
    pinMode(p2, OUTPUT);
    pinMode(p3, OUTPUT);
    pinMode(p4, OUTPUT);
  }

  // call in init() or before using
  void setup() {
    bool o[4] = { true, true, true, true };
    output(o);
  }

  // rotations per minute
  void setSpeed(float speed) {
    if (speed == 0) {
      this->stopped = true;
    } else {
      this->setDirection(speed < 0 ? -1 : 1);
      speed = abs(speed);
      this->stepDelay = 60L * 1000L * 1000L / this->numSteps / speed;
      this->stopped = false;
    }
  }

  void step() {
    if (this->stopped) return;

    bool o[4];

    switch (this->currentStep) {
      case 0:
        o[0] = true;
        o[1] = false;
        o[2] = true;
        o[3] = false;
        break;
      case 1:
        o[0] = false;
        o[1] = true;
        o[2] = true;
        o[3] = false;
        break;
      case 2:
        o[0] = false;
        o[1] = true;
        o[2] = false;
        o[3] = true;
        break;
      case 3:
        o[0] = true;
        o[1] = false;
        o[2] = false;
        o[3] = true;
        break;
    }

    output(o);

    this->currentStep = (this->currentStep + direction + 4) % 4;
  }

  void output(bool o[4]) {
    digitalWrite(this->p1, o[0]);
    digitalWrite(this->p2, o[1]);
    digitalWrite(this->p3, o[2]);
    digitalWrite(this->p4, o[3]);
  }

  // run this every "frame", in the loop() function
  void run() {
    unsigned long now = micros();

    if (now - this->lastStepTime >= this->stepDelay) {
      this->lastStepTime = now;
      this->step();
    }
  }

  // 1 or -1
  void setDirection(int dir) {
    if (this->direction == dir) {
      return;
    }

    this->direction = dir;

    int temp = this->p2;
    this->p2 = this->p3;
    this->p3 = temp;

    this->currentStep = 0;

    this->setup();
  }
};