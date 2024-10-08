---
title: "Calculating Compilers Effectively"
in: "Papers"
date: 2024-08-28
year: 2024
type: "posts"
draft: false
side_photo: "/images/side-effects.png"
links:
  - name: pdf
    link: /posts/calculating-compilers-effectively/paper.pdf
  - name: code
    link: https://zenodo.org/records/12771956
  - name: bib
    link: paper.bib
  - name: video talk
    link: https://tinyurl.com/ye4f9kfe
---

Zac Garby, Graham Hutton, and Patrick Bahr

*Haskell Symposium 2024*

### Abstract
Much work in the area of compiler calculation has focused on pure languages. While this simplifies the reasoning, it reduces the applicability. In this article, we show how an existing compiler calculation methodology can be naturally extended to languages with side-effects. We achieve this by exploiting an algebraic approach to effects, which keeps the reasoning simple and provides flexibility in how effects are interpreted. To make the ideas accessible we only use elementary functional programming techniques.
