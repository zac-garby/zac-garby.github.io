---
title: "Wayfinder"
prize: "Second Place"
photos:
    - "/images/hackathons/way1.png"
    - "/images/hackathons/way2.png"
    - "/images/hackathons/way3.png"
    - "/images/hackathons/way4.png"
    - "/images/hackathons/way5.png"
    - "/images/hackathons/way6.png"
video: "https://www.youtube.com/embed/q9bSCYCZBV0?si=nN3BAbE9Ew0gODi2"
date: "2025-02-08"
hackathon: "Royal Hackaway v8"
devpost: "https://devpost.com/software/wayfinder-l4673m"
---

Another great [Hackaway](https://www.royalhackaway.com)! This one is always a fun
event, and definitely makes the slightly annoying trip down to London worth it.

Also, excitingly, this was the first ever hackathon we've been to where every
single team from Nottingham won a prize! And there were five such teams.
So that was absolutely incredible: well done and congratulations to everyone
involved in the inaugural *Nottingham Sweep*! 🧹

It was just me and George this time, and while we meant to spend a while before
the hackathon brainstorming ideas, we arrived with pretty much nothing. Though,
the hacking period for Hackaway was 26.5 hours (oddly enough), so we had plenty
of time at the start to think of something cool.

We really like projects which combine the physical and the digital. I guess
"mixed reality" is the term. Our idea was this: a puzzle game, presented as a
dungeon crawler, where you can summon objects from the real world (via photo)
into your inventory. Then, for example, if I want to get through a door, I might
take a photo of my house keys.

The other fun little gimmick in our game is that you can take these items and
feed them into "machines". For instance, we might put a "tree" into the downgrader
machine to produce a "stick". Or, a "board" could become a more useful "sword".

I had two LLMs running on my poor laptop for this. We used
[Phi-4](https://ollama.com/library/phi4) to do the "logic" stuff (e.g., "what
happens if I combine these items?") and
[LLaVA](https://ollama.com/library/llava) for the image detection.

Honestly, I was shocked that my 16GB machine could even run one of these, let
alone two!

LLMs are a pain to work with. They act like toddlers. They *do not listen* to
you. They do not care what you want. I tried for approximately four hours to
convince Phi-4 that while yes, "hope" does rhyme with "rope", it is an
intangible noun and therefore the player cannot have "hope" in their inventory.
(I gave up, eventually. Try putting a rope into the rhyming machine...)

This was a really fun project though. I know I always say that after these
things, but, well, they usually are. I put a lot of effort in this one into the
polishing of it. Not just the UI, but also the code.

Most of the time, when I do web-based projects like this one, I end up with a
full-on spaghetti pile of bad code, but I figured: okay, I'm going to learn
to use TypeScript, and I am going to use Promises, and I'm going to lay this
frontend stuff out in a logical way that makes sense. And it worked! And typed
Python, as always, is incredible.

Another thing I always do, and which I was not able to avoid this time, is
over-scoping. I went into this wanting to do a chill project, something low-key
and easy, particularly because it was only me and George working on it. But, as
I should have expected, I really did end up just sitting in front of my laptop
for twenty-six hours straight.

Worth it though.

---

If you're interested, check out our project on the
[Devpost](https://devpost.com/software/wayfinder-l4673m) page!
