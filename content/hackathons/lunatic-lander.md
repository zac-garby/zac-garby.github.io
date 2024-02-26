---
title: "Lunatic Lander"
photos:
    - "/images/hackathons/lunar1.jpg"
    - "/images/hackathons/lunar2.jpg"
    - "/images/hackathons/lunar5.png"
    - "/images/hackathons/lunar3.jpg"
    - "/images/hackathons/lunar4.jpg"
prize: "Second Place"
video: "https://www.youtube.com/embed/Gr60kT17tq4?si=nRSpWaKOM4xqtm_g"
date: "2024-02-24"
hackathon: "AstonHack 9"
devpost: "https://devpost.com/software/lunatic-lander"
---

AstonHack 9 was my final hackathon of this hackathon season, and we had a lot of fun! George, Sol and I had these hardware sets which we won from Royal Hackaway a few weeks ago and wanted to make use of them for *something*, so we figured we'd do a hardware hack this time. Also, Artemis, who came too, is an electronic engineer, so you know, that helped.

Essentially we wanted to make a lunar lander simulator, but in real life.

Somewhat inspired by NASA's now-ancient [project LOLA](https://www.nasa.gov/image-article/project-lola/), our plan was to create a model of the moon, and rest it on a cradle of stepper-motor-controlled wheels to allow it to rotate in all three axes. A camera suspended above on a movable gantry would be the landing craft, and the game would be played via a laptop streaming the webcam's video.

Perhaps a little adventurous, this was one of those hacks that needed a fair bit of prep. The Thursday before the weekend I went to Hobbycraft and bought some supplies. Some foam balls originally made for flower arrangements. Some black card. Some paint. I threw all this in my suitcase along with as many tools and electronic *things* as I could fit. That, plus everyone else's similarly silly setups, wasn't quite enough, and we had to go for a mid-hackathon Birmingham trim to pick some bits up from B&M and Poundland and the likes.

The biggest problem I had with this project was trying to get the stepper motors working. We had three 28BYJ-48 steppers, each attached to ULN2003 boards, and in theory these are really to drive using the Arduino stepper motor library. They... are not. I mean, they work in one direction fine, but as soon as you reverse them you get problems. As in, they don't reverse.

I spent about 16 hours of the 24 hour hack trying to fix this, culminating in me writing a stepper library from scratch which properly handles these things! There are a few tricks. Swapping round the middle two pins makes it reverse, but only if you also reverse the order of steps, which nobody seems to say online. Oh well. If you want, you can download it here: [stepper.ino](/files/stepper.ino).

But that worked a treat, and then the rest of it came together nicely. There were problems with the other bits during development too, but I was so engrossed in my stepper motors that I was a bit oblivious to what was going on to be honest. Take a look at the video above for an idea of what the final product looked like though!

One fun thing is that the webcam we used didn't have auto-focus, so Artemis attached it up to another stepper motor via a belt so we could tele-operate the autofocus cuff on the lens. She had to make a gear out of hot glue...

And we came second! This was one hackathon where I was glad not to win, since I would've then been lugging a monitor back on the packed train. This was my last hackathon for the season--I think the next one will be around HackNotts time in November--but it was a great one to end on and I can't wait for the next!