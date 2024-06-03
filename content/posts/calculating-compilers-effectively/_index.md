---
title: "Calculating Compilers Effectively"
date: 2024-06-03
year: 2024
type: "posts"
draft: false
---

Zac Garby, Graham Hutton, and Patrick Bahr. Submitted to *the Haskell Symposium 2024*

### Abstract
Much work in the area of compiler calculation has focused on pure languages. While this simplifies the reasoning, it reduces the applicability. In this article, we show how an existing compiler calculation methodology can be naturally extended to languages with side-effects. We achieve this by exploiting an algebraic approach to effects, which keeps the reasoning simple and provides flexibility in how efefcts are interpreted. To make the ideas accessible we only use elementary functional programming techniques.

[\[paper.pdf\]](paper.pdf) [\[code.zip\]](code.zip) [\[paper.bib\]](paper.bib)