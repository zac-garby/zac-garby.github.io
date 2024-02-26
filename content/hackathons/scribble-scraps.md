---
title: "Scribble Scraps"
photos:
    - "/images/hackathons/scrap0.png"
    - "/images/hackathons/scrap1.png"
    - "/images/hackathons/scrap2.png"
    - "/images/hackathons/scrap3.png"
    - "/images/hackathons/scrap4.png"
prize: "First Place"
video: "https://www.youtube.com/embed/rDuBIISVbTI?si=-4lODe3xoR0IVFxj&amp;start=9037"
date: "2024-02-17"
hackathon: "HackSussex 2024"
devpost: "https://devpost.com/software/scribble-scraps"
---

Sussex is a very long way away from Nottingham, but this one was well worth the journey!

We went down in a five person team--Caleb, George, Sol, [James](https://frost.cx), and myself--with a few ideas in mind, but really settled on this one on the journey.

We wanted to make a web app, kinda like Pokémon, but with real life objects. Go somewhere, take a photo of an object, and watch it come to life, sprouting arms, legs, and being given attributes, stats, and types!

Our hope was that we would get it done early enough in the hack that we could distribute the link to the website to the other hackers and let people play around with it. And this actually worked out! It certainly took us a lot longer than we expected to get this into a playable state, but people really seemed to love it. One woman even sent it to her son in another country, so we have some international representation in our userbase already.

We also came up with some extremely detailed and over-complicated battle mechanics, courtesy of Caleb. Unfortunately, we weren't able to get these totally working, but the battle screen and game-joining logic works well so it's nearly at that point.

But even without battling, it is so incredibly fun to run around a hackathon scanning random objects and seeing their digital counterparts take form.

---

So how did we make it? As is tradition, our codebase was rather... hacky. First off, James and I wrote two separate inter-communicating backends, both [Flask](https://flask.palletsprojects.com/en/3.0.x/) servers, just so we didn't have to edit the same file and deal with merge conflicts. Then we had a third server for the front-end, which Sol made using React.

Actually, sidenote: this hackathon has provided me with a newfound hatred for React and Tailwind. I hope this is not a contraversial opinion.

Anyway, yeah. I think we ended up with five or six servers in total communicating with each other. We used an amazing Python library called [rembg](https://github.com/danielgatis/rembg) to segment our photos, and then [GPT-4](https://openai.com/product) to take these and assign them a name, nickname, description, and set of stats and types.

We didn't really want to do too much AI stuff, especially since our last project at Hackaway just a few weeks ago was very AI heavy, but this was really the only way to do that part of it.

It all worked a treat, honestly. We were very busy--I was literally typing at my computer for approximately 23 or the 24 hours we had for hacking--but it was worth it in the end. We got first place! I wasn't expecting it at all, but I'm really pleased with the outcome. Especially as the prize was a *Steam Deck*??

So to conclude. This really was one of the most fun hackathons I've been to in a long time, and I feel like we made a really cool project which genuinely brought a lot of people joy.

Take a look at our [Devpost](https://devpost.com/software/scribble-scraps) for a bit more info, if you're interested!

Also, you can play the game on [James' website](https://scribble-scraps.frost.cx)! I can't promise this will be functional forever, since I might run out of OpenAI credits if it gets too much use, but give it a go while you can!

If you want to mess around with it in the future and it's gone down, do please send me an email and I'll try and get it going again.