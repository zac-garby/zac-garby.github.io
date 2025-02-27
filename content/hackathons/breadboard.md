---
title: "Breadboard"
photos:
    - "/images/hackathons/breadboard1.jpg"
    - "/images/hackathons/breadboard2.jpg"
    - "/images/hackathons/breadboard3.jpg"
    - "/images/hackathons/breadboard4.jpg"
    - "/images/hackathons/breadboard5.jpg"
video: "https://www.youtube.com/embed/1y_qIp2YdMw?si=uG1hJVkKcbU4iH0v"
date: "2025-02-22"
hackathon: "Astonhack 10"
devpost: "https://devpost.com/software/breadboard-hacknotts-3"
---

We made a toast printer!

It kinda worked. And none of us were electrocuted, working in sleep-deprived
conditions with mains voltages. That, in itself, is a victory as far as I'm
concerned.

This was a project with myself, [Adrian](https://adrianvecinatercero.co.uk),
Daudi, and [James](https://www.frost.cx). We've been wanting to make something
silly for ages, and we took this opportunity to do just that. We arrived in
Birmingham on Saturday morning and our first task was, naturally, to go to the
closest charity shop and buy a £4 toaster.

Our idea was that we could in theory print an 8x8 grid of pixels onto a piece
of bread, by dividing the heating element inside the printer into eight and
modulating each sub-element on and off while raising the bread. Sounds simple
right?

I mean one thing was that it's absolutely terrifying working on a toaster. It
is literally just a big wire plugged into mains, with some controls and stuff.

But with that out of the way (as you will note in the second photo, I am using
a wooden spoon to press the toast button, so all's good), there were still a
bunch of problems. I spent a long time on the circuitry around the heating
elements, and also the general disassembly (this toaster had safety screws and
we did not have a safety screwdriver).

The thing with heating elements is that while they do get hot, they take a long
time to turn bread into toast, especially when divided by eight. So we needed
to make physical contact between the elements and the bread surface in order to
burn the image on. But in doing so, the bread would scrape and bend the
carefully positioned elements.

This being the case, a lot of time was spent just fighting with the specific
arrangement of the internals of the toaster. We also had to create a heat
shield out of foil, inside the toaster, so that the back of the bread didn't
burn before the front could cook. Have you ever been told not to put metal in
a toaster? Yeah. Me too. But we're all grown-ups here.

Daudi, in fitting with his character, wrote a little DSL analogous to g-code for
controlling and programming images into the bread printer. Plus, an
image-to-B-code compiler. Cool!

In the end, well. We didn't get any *fantastic* prints, but we did get some
decent results. I was naively hoping to be going back home with a fully
functional toast printer, but I should've known. It ended up in a bin in the
hacking room at Aston. Either way, I'm really happy with how it came out, and
we definitely did achieve our stated goal of something "silly".

Check out the extra write-up on our
[Devpost](https://devpost.com/software/breadboard-hacknotts-3)!
