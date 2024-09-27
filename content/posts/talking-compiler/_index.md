---
title: "I want to talk to my compiler"
in: "Blog"
date: 2024-09-27
type: "posts"
draft: true
side_photo: "/images/talkative.png"
---

What might the future of programming look like? This is the first in a series of articles which I plan to write, hopefully answering this question (optimistically, at least).

A little while ago, I gave a [lightning talk](https://www.youtube.com/watch?v=ZKSY8DfiFs8) for [HackSoc](https://hacksocnotts.co.uk) in Nottingham about a program synthesis project I'd been working on for my [fourth year dissertation](https://github.com/zac-garby/diss/tree/master/fugue). A little while before that, I gave a talk on "the future of programming", where I argued that program synthesis, interactive editing, holes, and what I would like to call **"conversational programming"**, really are---or at least should be---where things are going.

In this post, I want to put these thoughts down into one place, and expand on them a bit. Therefore this post will be about this paradigm of conversational, back-and-forth, interactive, mutual, reciprocal, talkative---or other similar adjective---programming.

The other aim of this post is to serve as a broader introduction to this series. I will start off speaking specifically about "holes", and other ways in which compilers can be talkative. I will then explore, and I suppose fantasise about, some more niche and exciting future avenues for developments in this area. This should hopefully set the scene nicely for my next few posts.

---

Firstly, a little context on paradigms. In some circles, there seems to be something of a conflict between functional and imperative programming. "Obviously!", we claim, "functional programming is superior!". Now to be clear, I am definitely a Functional Programming Enjoyer. As somebody currently doing a PhD at Nottingham's [FP lab](https://www.nottingham.ac.uk/research/groups/fp-lab/), I admit I'm perhaps slightly biased.

That being said, I want to start this post off by saying that, although I will be presenting most of the ideas here in the context of the functional paradigm, there is nothing about them which makes this an inherent choice. So if you're not yourself a Functional Programming Enjoyer, please don't be put off by this.

---

<!-- Holes, intro to conversational style -->
### How I write programs

Have you ever used [Agda](https://wiki.portal.chalmers.se/agda/pmwiki.php)? If you have, you'll be familiar with how the Emacs mode makes writing code very pleasant. But in case you haven't, I'll try and give you a quick overview.

I don't use Agda all that much though, so I'll demonstrate with my toy functional language, [Fugue](https://github.com/zac-garby/diss/tree/master/fugue). Suppose we want to write a function that reverses lists. Simple enough, hopefully!

```
reverse : [a] -> [a];
```

So we start off with the type signature: a function (`->`) from a list of *things*, `[a]`, to another list of things of the same type. The aim is to let the types guide the construction of our program---something the [Idris](https://www.idris-lang.org) people called "type-driven development".

Some languages support this paradigm better than others. Functional programming languages tend to be particularly good for it, since they *tend to* have stronger, more descriptive type systems.

In Fugue, we can express our intent by writing ...
```
reverse xs = ?;
```
In other words, "I have no idea how to write this function, please help me out!". The question mark stands for a *hole*: a piece of the program which we've intentionally left blank.

This lets us ask the compiler for help before the program is finished. Fugue tells us:
```
  error:
  • found holes in ∀ a . List a → List a:
    hole 0:
    | wants : List a
    | given:
    |   reverse : List a → List a,
    |   xs : List a
    | fits include:
    |   xs : List a,
    |   reverse x0 : List a
    |     x0 : List a,
    |   Nil : List a
    |   ... (12 more) ...
    '---
```
In other words, "Your hole should be a list of things. You've got a few variables at your disposal (the argument `xs`, and the option to make a recursive call to `reverse`)." It goes on to list a few options.

Knowing that I want a list of things, and that I probably want to do something with `xs`, I would introduce a case-split.
```
reverse xs = case xs of
  Nil -> ?,         -- empty list
  Cons x xs' -> ?;  -- x, followed by xs'
```
Now we have two holes! This is getting out of hand.

Ok, well, no. Breaking down programs into smaller chunks and dealing with them separately is a huge boon of this conversational, incremental, interactive approach. Fugue replies with two holes:
```
  error:
  • found holes in ∀ a . List a → List a:
    hole 0:
    | wants : List a
    | given:
    |   reverse : List a → List a,
    |   xs : List a
    | fits include:
    |   xs : List a,
    |   reverse x0 : List a
    |     x0 : List a,
    |   Nil : List a
    |   ... (12 more) ...
    '---
    hole 1:
    | wants : List a
    | given:
    |   reverse : List a → List a,
    |   x : a,
    |   xs' : List a
    | fits include: [ ... omitted ... ]
    '---
```
We are at liberty to deal with the first one, and to totally ignore the second hole until we're ready.

Remember that the first hole is the case for the empty list. This is pretty trivial: reversing an empty list should be... an empty list. So we can fill that in! And note, that was one of the suggested hole-fits: `Nil`, also written `[]`.
```
reverse xs = case xs of
  Nil -> Nil,
  Cons x xs' -> ?;
```
With that, we can move onto the second hole. Let's look at the info it gives us in more detail.
```
  error:
  • found holes in ∀ a . List a → List a:
    hole 0:
    | wants : List a
    | given:
    |   reverse : List a → List a,
    |   xs : List a,
    |   x : a,
    |   xs' : List a
    | fits include:
    |   xs' : List a,
    |   xs : List a,
    |   reverse x0 : List a
    |     x0 : List a
    |   ... (13 more) ...
    '---
```
So given the head of the list `x`, and the remaining portion `xs'`, we need to put together something which looks like the whole list, but reversed.

Probably, we'll want to join two lists together. Therefore, lets split the hole into two, again. (`++` is the list appending operator.)
```
  Cons x xs' -> ? ++ ?;
```
I won't go into too much detail on the rest of this exercise, but we're nearly done. We end up with the expected program:
```
reverse : [a] -> [a];
reverse xs = case xs of
  Nil -> Nil,
  Cons x xs' -> reverse xs' ++ [x];
```
Ok. So I guess this program is pretty trivial, all things considered. But this paradigm of dealing with small parts, and having support from the compiler in doing so, is extremely powerful. Especially when type information is exploited, and possible hole fits are highlighted.

### Holes, in practice

So, holes are available in quite a few languages nowadays. Fugue isn't special (or at least, not in this way).

Agda has some amazing support for holes, and plays nicely with Emacs to let you interactively deal with them without having to manually re-run your program each time.

Haskell has holes, too! You may not have known this, and they can feel a little clunky at times, but you can write a hole as any variable beginning with an underscore.
```
ghci> 1 + _foo

<interactive>:2:5: error:
    • Found hole: _foo :: a
      Where: ‘a’ is a rigid type variable bound by
               the inferred type of it :: Num a => a
               at <interactive>:2:1-8
      Or perhaps ‘_foo’ is mis-spelled, (...)
    • In the second argument of ‘(+)’, (...)
      In the expression: 1 + _foo
      In an equation for ‘it’: it = 1 + _foo
    • Relevant bindings include it :: a (...)
      Constraints include Num a (...)
```
(*Shudder*... All that textual noise...)

Holes seem a little less prevalent in imperative languages. It could just be that I'm using less of these language, and so haven't come across them, but perhaps also the different in type systems comes into play here.

Holes are particularly useful with a strong type system. The more that the compiler enforces the value that you stick inside a hole, the more it can tell you about it, and thus the more useful holes become.

Agda is an especially nice demonstration of this concept. Since it uses a dependent type system, you can express *very* strong properties, and as a result, a lot of the time the compiler can infer *precisely* what you have to write in a hole.

### Other aspects of conversationality

Conversational programming is more than just interacting with holes. It's hinted at, and assisted by, lots of other features which have been present in the programmers' toolkit for a long time. And, as we'll see, it's pervasive in---and forms a basis for---much of the future posts in this series of articles on *the future of programming*.

We even get a whiff of conversational programming in places as benign as syntax highlighting. You could argue that your editor tokenising (or ideally, parsing) your code and then feeding back to you with colours is a minimal conversation.

"Hey, editor! I've written this code - what do you think?", you ask. "Hmmm", it replies, taking its time because inevitably it's written in [Electron](https://www.electronjs.org). "I don't know what it does, but I think I can make out the structure in it."

The great thing about this is that, like other forms of conversation, *the understanding of the topic at hand (namely the program) is strengthened for both parties*. You gain a better understanding of your code's structure; and the editor, having parsed it, can now potentially apply some transformations or other syntax-based actions.

A type system also reinforces this reciprocal fashion of programming, and again, both parties (you and the compiler) gain more information, and become better at their jobs.

The type system aids you, as a programmer, by reducing cognitive overhead, providing a feeling of safety and security, and allowing for *type-driven development*. And of course, it aids the compiler too, allowing for more optimisations, better error messages. It can also help the editor you're using, improving contextual information.

A final example for now of existing, commonplace conversational features is interactive debuggers and breakpoints. These are explicitly interactive, and often are indeed framed as a "conversation", where the programmer types commands and the debugger responds.

As we've seen, then, support for a conversational programming experience exists not in the language, not in the compiler, nor in the editor, but rather the interplay between all of these systems.

In future articles, I'll talk about more prospective features which can in theory greatly aid this approach to writing code. That's not to say that these features are non-existent, but they are certainly more niche. In particular:

 - **Structural, or semi-structural, editing**. A belief of mine is that text is *not* the optimal medium for writing code. Think of it this way: why do we use plaintext? Historically, it's because that's what was available (and it was more convenient than punchcards).

   Text, however, is not how we *think* about code, and it's also not how compilers *think* about code (note, the word *think* in these two cases has very different meanings). Therefore, it's perhaps a lossy interface between human intention and computer understanding. Is there a better way? (Hint: not [Scratch](https://scratch.mit.edu), as much as I do love it.)

 - **Program synthesis**. Whether it be algorithmic (analytical? enumerative?) program synthesis (see [Fantasia & Fugue](https://fplunchnott.wordpress.com/2023/10/20/fantasia-and-fugue-synthesising-recursive-functions/)) or machine-learning based (think [Copilot](https://github.com/features/copilot) or newer ideas like what [Cogna](https://www.cogna.co) is doing), program synthesis aims to take some of the overhead and tedium away from the programmers.

   For reasons which I am excited to dive into more details on soon, my belief is that program synthesis and holes play *very* nicely together. For instance, take a look at [SnipPy](https://snippy.goto.ucsd.edu).

 - **Equational reasoning**. Something which I'm [very interested in](/posts/calculating-compilers-effectively) is equational reasoning about programs. This is a superpower in functional programming languages: referential transparency allows us to treat function definitions truly as "equations". Further, we can write specifications for programs as equations, and then *solve them*, producing programs for free.
  
   Equational reasoning to my knowledge has not found its way into any interactive tools thus far, but doing so would be extremely powerful. Additionally, equational reasoning leads to an explorative, almost "tree-searching" mode of programming. And so...

 - **Tree-based code exploration**. And by this I mean exploiting the fact that the search space of "possible programs" can be seen as a tree. Consider the example of holes earlier in this article, and note that at each decision point, I could have done a few things.

   If I make one decision, and decide to backtrack, I have to keep the context in my mind. It would be wonderful if an editor and/or a compiler could support such a process natively, allowing us to explore possible definitions easily without sacrificing the precious code we've already written.

   I actually found a very interesting essay on this topic, at [this link](https://blog.dziban.net/essays/explorative-programming/), but unfortunately it seems to have since gone down. I hope this isn't forever. Other concepts like [Unison's](https://www.unison-lang.org/docs/the-big-idea/) content-addressed code can potentially play nicely with this sort of thing, and this is something I'd like to explore.

I will go into much more detail on these topics in future posts, so stay tuned! All of these items are extremely interesting in their own right and deserve exploration of their own, but are also supremely relevant to a conversational approach, so I feel that I should mention them here.

### What's next?

That's mostly what I wanted to say in this article, I think. Maybe this all seems a bit vague and fantastical so far, but that's kind of the point! I've been thinking a lot about what the future of programming languages could look like, and I want to get some of these ideas out there and maybe inspire other people to think along these same lines.

While the conversational approach to programming is very much usable at this point in time in all the best* languages, I hope that I've succeeded in setting out some things which would really take it to the next level.

There's some truly low-hanging fruit in this area, and also some work which I expected would take years and years to do properly. I'm going to be slowly working my way through some of these things, exploring this area and trying to put together a system which works exactly how I want it. It's likely that my goals will change, in the process---that's the plan, at least.

Finally, if you have any thoughts on all this, or ideas, or if you disagree with me, or if you just want to say "Hi!", then please do get in touch! My contact details are on [my website](/), and I always like talking to people about programming language stuff.

<!-- 
Where can this be improved:

 - interactive interface (errors are scary! make it more obvious)
 - showing values/possible values when known (e.g. in a case) of holes
 - 
 -->

<!-- Structural editing. Hazel, Agda, etc. What's good? What's bad? -->

<!-- Why use text? -->

<!-- Program synthesis (large scale/small scale. ChatGPT vs Hoogle+. AI vs analytical) -->

<!-- Equational reasoning and tree-based exploration -->

<!-- Learning by example (Snippy) -->

<!-- Calculation  -->

<!-- Putting it all together. What's left to do? -->