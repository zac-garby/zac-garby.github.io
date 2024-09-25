---
title: "I want to talk to my compiler"
in: "Blog"
date: 2024-04-17
type: "posts"
draft: true
side_photo: ""
---

What might the future of programming look like?

A little while ago, I gave a [lightning talk](https://www.youtube.com/watch?v=ZKSY8DfiFs8) for [HackSoc](https://hacksocnotts.co.uk) in Nottingham about a program synthesis project I'd been working on for my [fourth year dissertation](https://github.com/zac-garby/diss/tree/master/fugue). A little while before that, I gave a talk on "the future of programming", where I argued that program synthesis, interactive editing, holes, and what I would like to call **"conversational programming"**, really are---or at least should be---where things are going.

In this post, I want to put these thoughts down into one place, and expand on them a bit. I want to try to explain to you what, in my opinion, programming *should* (and feasibly might) look like, say, ten years down the line.

(Firstly, a little context on paradigms. In some circles, there seems to be something of a conflict between functional and imperative programming. "Obviously!", we claim, "functional programming is superior!". Now to be clear, I am definitely a Functional Programming Enjoyer. As somebody currently doing a PhD at Nottingham's [FP lab](https://www.nottingham.ac.uk/research/groups/fp-lab/), I admit I'm perhaps slightly biased.

That being said, I want to start this post off by saying that, although I will be presenting most of the ideas here in the context of the functional paradigm, there is nothing about them which makes this an inherent choice. So if you're not yourself a Functional Programming Enjoyer, please don't be put off by this.)

---

<!-- Holes, intro to conversational style -->
### How I write programs

Have you ever used [Agda](https://wiki.portal.chalmers.se/agda/pmwiki.php)? If you have, you'll be familiar with how the Emacs mode makes writing code very pleasant. But in case you haven't, I'll try and give you a quick overview.

I don't use Agda all that much though, so I'll demonstrate with my toy functional language, [Fugue](https://github.com/zac-garby/diss/tree/master/fugue). Suppose we want to write a function that reverses lists. Simple enough, hopefully!

```
reverse : [a] -> [a]
```

So we start off with the type signature: a function (`->`) from a list of *things*, `[a]`, to another list of things of the same type. The aim is to let the types guide the construction of our program---something the [Idris](https://www.idris-lang.org) people called "type-driven development".

Some languages support this paradigm better than others. Functional programming languages tend to be particularly good for it, since they *tend to* have stronger, more descriptive type systems.

In Fugue, we can express our intent by writing ...
```
reverse = ?
```
In other words, "I have no idea how to write this function, please help me out!".

<!-- Structural editing. Hazel, Agda, etc. What's good? What's bad? -->

<!-- Why use text? -->

<!-- Program synthesis (large scale/small scale. ChatGPT vs Hoogle+. AI vs analytical) -->

<!-- Learning by example (Snippy) -->

<!-- Putting it all together. What's left to do? -->