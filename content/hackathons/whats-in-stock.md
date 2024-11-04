---
title: "What's in stock?"
photos:
    - "/images/hackathons/soup1.jpg"
    - "/images/hackathons/soup2.jpg"
date: "2024-11-02"
hackathon: "HackNotts '24"
devpost: "https://devpost.com/software/what-s-in-stock-itzk3l"
---

> "Minimising your minestrone"

Spurring comments like "surprisingly palatable" and "looks like porridge", we present to you: *What's in stock?*. Hot and steaming from the kitchen of myself, George Townsend, and James Frost.

We set out to find the optimal soup. Optimal, in the sense that it should be the cheapest possible way, armed with a soup maker, to meet your macro- and micro-nutrition targets every single day.

This consisted two main components: the scraping and nutrition information extraction, and the solver.

Our aim with the scraper was to download the nutritional information from every single item on the Tesco website. That data only includes macros, most of the time, but is nicely formatted at least. We thought we could then match that up "somehow" with a more complete nutritional database I already had, which would give us micro-nutrients.

Two problems.

Firstly, Tesco doesn't like us anymore, and wouldn't let us do anything more than scraping the item listings (so at least we had their names and prices) and a few item pages. We tried everything: running on various cloud servers, using selenium, and all sorts of other tricks, but nothing worked, so we had less data to go on that we had hoped.

Secondly, this "matching" process is difficult, since a straight-up fuzzy search based on the names of the items is not enough. We essentially have a semantic search problem, and so I had to pull out an embedding model to tell us the similarity between each item and each Tesco item. This... mostly works, but there are still cases where the wrong item comes up.

But in the end, we had assembled a database of macro- and micro-nutrients per 100g for around three-thousand items, as well as Tesco product page URLs and, importantly, their prices *per 100g*.

The solver we used in the end was a very complicated invocation of scipy's `minimise` function. You know when you're trying to optimise for about three different variables at the same time? And you're not sure exactly how to encode them? Or how they should be weighted? Yeah.

But to be honest, even coming across this function was a windfall, because we were trying all sorts of things beforehand, with a solver written by James which was something like a greedy bin-packer, and a clunky attempt by me of a simulated annealer.

Either way, we got it working! Amazingly, we actually got something resembling a soup recipe.

 1. Add to a pot:
   - 126g black beans
   - 53g barley
   - 95g cereal
   - 49g whole wheat bread
   - 88g almonds
   - 20g whole wheat biscuits
   - 15g baked beans
   - 38g flour
 2. Soup

And yes, we actually did make this. At the hackathon, yep. George brought along his soup maker, and we had an ad-hoc Tesco trip at 11am just before judging started.

The judges loved* it. And it was sort of soup, if you call porridge soup. Genuinely, though, it tasted better than I had expected. And this soup has:

 - 2144kcal
 - 68g fat (7g saturated)
 - 313g carbs (13g sugars)
 - 70g protein

So... your whole day's eating, right?

This was one of the few hackathons where the next day (i.e. today, Monday, the day I'm writing this), I spent *more time* on the project. I've been extending it with all sorts of improvements to the optimiser, and I have put together an optimal diet which will actually be enjoyable to follow. So, that's my plan now. I'll keep you posted.