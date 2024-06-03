---
title: "I want to talk to my compiler"
date: 2024-04-17
type: "posts"
draft: true
side_photo: "press.gif"
---

... or, *what might the future of programming look like?*

---

A little while ago, I gave a [lightning talk](https://www.youtube.com/watch?v=ZKSY8DfiFs8) for [HackSoc](https://hacksocnotts.co.uk) about a program synthesis project I'd been working on for my [fourth year dissertation](https://github.com/zac-garby/diss/tree/master/fugue). A little while before that, I gave a talk on "the future of programming", where I argued that **program synthesis**, **interactive editing**, **holes**, and what I would like to call **"conversational programming"**, really are---or at least should be---where things are going.

In this post, I want to put these thoughts down into one place, and expand on them a bit. I want to try to explain to you what, in my opinion, programming *should* (and feasibly might) look like, say, ten years down the line.

### Context: Paradigms

In some circles, there seems to be something of a conflict between functional and imperative programming. "Obviously!", we claim, "functional programming is superior!". Now to be clear, I am definitely a Functional Programming Enjoyer. As somebody currently doing a PhD at Nottingham's [FP lab](https://www.nottingham.ac.uk/research/groups/fp-lab/), I admit I'm perhaps slightly biased.

That being said, I want to start this post off by saying that, although I will be presenting most of the ideas here in the context of the functional paradigm, there is nothing about them which makes this an inherent choice. So if you're not yourself a Functional Programming Enjoyer, please don't be put off by this.

### Context: What is a compiler?

While I have your attention, and at the risk of losing it: here's another quick tangent. Although superficially it might seem like almost a trivial question to any programmer, I ask you: what is a compiler exactly?

Something which lives on your computer and turns code into something else? What, then, is code? What is "something else"? In what sense is `ghc` a compiler, while the Java Virtual Machine<aside>And yes, by the way, I do mean the *virtual machine*, not the `javac`, which is "obviously" a compiler.</aside> is not? Or is it?

It turns out this question is actually really interesting, especially when we start looking at *calculating* compilers (e.g. [Bahr and Hutton, 2015](https://www.cambridge.org/core/services/aop-cambridge-core/content/view/70AA17724EBCA4182B1B2B522362A9AF/S0956796815000180a.pdf/calculating-correct-compilers.pdf)), because we have to specify these things somehow. I think there are fun [categorical](https://en.wikipedia.org/wiki/Category_theory) answers to this, which I really want to explore, and which have been approximately explored already by the likes of [Conal Elliott](http://conal.net/papers/calculating-compilers-categorically/) in a number of papers and [Erik Meijer](https://repository.ubn.ru.nl/bitstream/handle/2066/114054/mmubn000001_136175155.pdf) in his thesis from 1992.

Anyway, **for the purposes of this article**, when I say "compiler" I really do mean a compiler in the common sense: a program, like `ghc` or `gcc`, which turns code (and we all know what "code" means, right?) into some lower-level code (or perhaps runs it directly---arguably, running it directly is converting to lower-level "code" where that low-level code is precisely the semantic domain of the language).

---

### How I write programs

