---
title: "The Calculated Typer"
in: "Papers"
date: 2025-02-28
year: 2025
type: "posts"
draft: false
links:
  - name: pdf
    link: /posts/the-calculated-typer/paper.pdf
  - name: code
    link: /posts/the-calculated-typer/code.zip
  - name: bib
    link: /posts/the-calculated-typer/paper.bib
---

Zac Garby, Patrick Bahr, and Graham Hutton

*Submitted to [ICFP '25](https://icfp25.sigplan.org)*

### Abstract

We present a calculational approach to the design of type checkers,
showing how they can be derived from behavioural specifications using equational
reasoning.  In addition, we show how the calculations can be simplified by
taking an algebraic approach based on fold fusion, and further improved by
taking a constraint-based approach to solving and composing fusion
preconditions.  We illustrate our methodology with three examples of increasing
complexity, starting with a simple expression language, then adding support for
exceptions, and finally considering a version of the lambda calculus.
