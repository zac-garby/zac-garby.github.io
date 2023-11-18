---
title: "Knuckles"
prize: "Best in-person hack"
photos:
    - "/images/hackathons/knuckles1.jpg"
    - "/images/hackathons/knuckles2.png"
    - "/images/hackathons/knuckles3.jpg"
video: "https://www.youtube.com/embed/prHXzJ-Dfnk"
date: "2023-02-18"
hackathon: "HackSussex 2023"
---

*Knuckles* was a project I worked on for *HackSussex 2023* with a few friends—Sol, Jacob, George, and Xu. We'd seen videos of people using [nitinol](https://en.wikipedia.org/wiki/Nickel_titanium), an alloy of nickel and titanium, to lift weights! It's a shape-memory alloy, meaning that when heated, it contracts and returns to a set position. If its set position is a coiled spring, it can pull a not-insignificant weight.

We figured we could use this property to move the fingers on a robotic hand. Attaching these springs with one end at the top of the finger and one end at the base, contractions of the metal would contract the finger, just like real tendons. And this worked!

Well, eventually it worked. Like all hackathons, we had our share of problems here. We went through four different prototype finger/tendon designs (initially just two wooden dowels with a knuckle made of heat-shrink—this was too flexible in the lateral direction) settling on a more complex design with elastic bands for tensioning, brass split-pins for limiting lateral movement, and rubber finger-pads to help with grip. We even set up a desk fan to help cool the nitinol more quickly, increasing response time.

We also had problems with tempering the nitinol (i.e. heating it up and quickly cooling it to set its return shape). I can only imagine the *HackSussex* organisers were a little suspicious of us regularly heading outside, standing in a circle, and lighting many fires in the middle of the night. Sorry Josh: I'm sure that wasn't on your risk assessment.

But in the end, we got it working. And quite nicely, if I may say so myself! We hooked it up to a computer vision system so we could control the fingers with our own, and then had fun activating the very satisfying, clicky, relay sounds for hours on end.

Take a look at our [Devpost submission](https://devpost.com/software/knuckles) for a more thorough breakdown, and more cool photos and videos!
