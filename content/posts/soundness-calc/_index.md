---
title: "Sound-by-construction type systems"
in: "Papers"
date: 2026-02-12
year: 2026
type: "posts"
draft: false
links:
  - name: pdf
    link: /posts/soundness-calc/paper.pdf
  - name: Agda formalisation
    link: /posts/soundness-calc/agda.zip
  - name: bib
    link: /posts/soundness-calc/paper.bib
---

Patrick Bahr, Zac Garby, and Graham Hutton

*In preparation for ICFP '26*

### Abstract

Type systems for programming languages are usually designed by hand,
with the aim of satisfying a type soundness property that guarantees
well-typed programs cannot go wrong.  In this article, we show how
standard techniques for *proving* type soundness can be used in
reverse to systematically *derive* type systems
that are sound by construction.  We introduce and illustrate our
methodology with a series of practical examples, including a typed
lambda calculus with conditionals and checked exceptions.
