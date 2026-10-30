---
title: "Logicverse"
prize: "Second place"
photos:
    - "/images/hackathons/logicverse1.jpg"
    - "/images/hackathons/logicverse4.png"
    - "/images/hackathons/logicverse5.png"
    - "/images/hackathons/logicverse6.png"
    - "/images/hackathons/logicverse2.png"
    - "/images/hackathons/logicverse3.jpg"
video: "https://www.youtube.com/embed/vmP9_vpKpl0"
date: "2026-10-25"
hackathon: "HackNotts 2026"
devpost: "https://devpost.com/software/logicverse"
---

Welcome to the Logicverse.

We wanted to make a simulation of humanity, in the online era. It works almost completely deterministically---by that I mean, no LLMs were used in the operation of this universe.

The Logicverse is a TV screen.
Sit down in front of it and you will be transported into its inner logical world.
A webcam picks up your face, we match you against pictures that we have scraped from the web, and figure out who you are.

Once we know your face and your name, we can match this to deeper facts such as your likes and dislikes, your GitHub repositories, your preferred programming languages, and other people who you know.

## Analytical conversationalist

We scraped a bunch of data from the HN discord, GitHub, LinkedIn (we got banned 4 times), Devpost about the interests, likes, projects, histories, and more of our fellow hackers.

All of these are stored as relational facts in a vast database.
To give you some idea, we put together more than one hundred thousand 'facts' about the other hackers at HackNotts.

Conversation is then entailed from these facts by means of dozens of handwritten inference rules.
(I think this is how real humans perform conversation, too?)

For example, the following query SPARQL identifies a possible topic of conversation between two interlocutors who recently "did a similar activity".
This is indicated by the `<didRecently>` relation. The knowledge-base engine can run dozens of these queries against tens of thousands of facts and figure out possible dialogue.
(By the way, SPARQL is an incredible language, as is the RDL data definition language that goes with it.)

```sparql
SELECT ?cmd
WHERE {
    GRAPH <metaverse/graph/scene> {
        ?A <is> <present> .
        ?B <is> <present> .
        ?A <alias> ?aliasA .
        ?B <alias> ?aliasB .
    }
    ?A <didRecently> ?activity .
    ?B <didRecently> ?activity .
    ?activity <name> ?activityName .
    FILTER (?A != ?B)
    BIND (CONCAT(
        ?aliasA, " (to ", ?aliasB, "): Have you been doing ", ?activityName, " lately? So have I!\n\n",
        ?aliasB, ": Great minds."
    ) as ?cmd)
}
```

Sometimes people will have very little in common, in which case we encode topics of possible smalltalk, and in the extreme case, topics that an individual may talk or think about with themselves.

## Formal speech

The dialogues are presented as scripts in a custom domain specific language that we designed.

```
[Zac wearing short long wig, costume XY3P ]
[Amber wearing blonde long wig, costume AG0R , ginger beard]
[enter Zac from stage left]
Zac: I think, therefore I am.
[enter Amber from stage right]
[cross Amber to Zac]
amber (to Zac): I won First Place at HackNotts '25, did I mention?
Zac (thinking): Only every time we meet.
```

These dialogues are chosen from a selection presented deterministically by our librettist (a Rust module), and sent to the renderer to be realised in the real world. The renderer interprets these stage directions line by line just as humans would.

## Who's there?

When a human sits down in front of our TV,

![](/images/hackathons/logicverse1.jpg)

our system knows. It figures out who has appeared, and creates a virtual alter-ego of them within the screen. These are the subjects and the objects of our facts and relations, and of the conversations to be had with the other inhabitants.

## Tech

We wrote the project in pretty much all Rust--taking a fairly low level approach to the graphics with Bevy--plus a little Python for some web scraping.

The knowledge-base is built with the amazing [SPARQL](https://www.w3.org/TR/sparql11-query/#QSynLiterals) query language against RDL Turtle data.

## Scraping

We wrote scrapers for Discord, Github, and Devpost. Discord was the hardest because we had no admin access. Instead we automated the browser, scripting the clicks that open each member’s full profile and reading the HTML.

GitHub and Devpost were easier, since both expose their data in a structured form. Devpost was especially useful because many people list their full names. We use those names in the display and in the script language.

We also linked the profiles with relations such as “collaborates with” and “follows”, and with identity links that connect one person’s accounts across platforms.
