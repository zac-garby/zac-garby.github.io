---
title: "Haskelltron 2000"
type: "special"
layout: "hackathon"
photos:
    - "/images/hackathons/haskelltron.jpg"
    - "/images/hackathons/haskelltron2.jpg"
    - "/images/hackathons/haskelltron3.jpg"
    - "/images/hackathons/haskelltron4.jpg"
    - "/images/hackathons/haskelltron5.jpg"
prize: "Hackiest Hack"
video: "https://www.youtube.com/embed/Ihw_dXDtOdc"
date: "2020-09-01"
hackathon: "HackNotts 2020"
---

I was in need of a way to let even more people know that Haskell is my
favourite language. This is the solution. Also, a very fast way for me to
develop a deep hatred for relays and MOSFETs (even if *it was my fault okay*).

This was my project for *HackNotts 2020*, which was actually an online
hackathon (COVID moment). That sucked, honestly. The best thing about hackathons
is doing things with people. But it did make it easier to do a big hardware
project, so I got this old receipt printer pretty cheap off Ebay.

After printing out the entire Bee Movie script on a receipt, I got to coming up
with an actual project idea. I've always wanted a portable computer in a
briefcase to carry around, and even better if it can print results out on paper
tape, so this was the perfect thing for it.

Essentially, this is a Haskell terminal hooked up to a receipt printer and an LCD
screen to show the line as you're typing. Sounds simple, right?

Nope!

Well, I won't go into too much detail here, but suffice to say, trying to hack
the internals of a receipt printer is deceptively difficult. Especially for
somebody like me who really doesn't know all that much about electricity.
Problem was, I wanted the printer to pull the paper back in before printing, so
it could print on consecutive lines without gaps, but also showing the user the
text which had just been printed. There's quite a gap between the print head
and the outside of the machine, so I had to selectively reverse the stepper
motor to get it to do this. And oh, *what a pain that was.*

Long story short, my MOSFET was the wrong way round. But do have a look at
[my writeup on Devpost](https://devpost.com/software/the-haskelltron-2000) for
a much longer, detailed account of what exactly went wrong. In the end, though,
it worked well, I think!
