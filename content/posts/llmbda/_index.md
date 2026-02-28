---
title: "The LLMbda Calculus"
in: "Papers"
date: 2026-02-11
year: 2026
type: "posts"
draft: false
links:
    - name: arXiv
      link: https://arxiv.org/abs/2602.20064
---

Zac Garby, Andrew D. Gordon, and David Sands

*Submitted to CSF '26*

Preprint PDF to appear on arXiv soon.

### Abstract

A conversation with a large language model (LLM) is a sequence of prompts and responses, with each response generated from the preceding conversation. AI agents build such conversations automatically: given an initial human prompt, a planner loop interleaves LLM calls with tool invocations and code execution. This tight coupling creates a new and poorly understood attack surface. A malicious prompt injected into a conversation can compromise later reasoning, trigger dangerous tool calls, or distort final outputs. Despite the centrality of such systems, we currently lack a principled semantic foundation for reasoning about their behaviour and safety. 

We address this gap by introducing an untyped call‑by‑value lambda calculus enriched with dynamic information‑flow control and a small number of primitives for constructing prompt‑response conversations. Our language includes a primitive that invokes an LLM: it serializes a value, sends it to the model as a prompt, and parses the response as a new term.

This calculus faithfully represents planner loops and their vulnerabilities, including the mechanisms by which prompt injection alters subsequent computation. The semantics explicitly captures conversations, and so supports reasoning about defenses such as quarantined sub‑conversations, isolation of generated code, and information‑flow restrictions on what may influence an LLM call. A termination‑insensitive noninterference theorem establishes integrity and confidentiality guarantees, demonstrating that a formal calculus can provide rigorous foundations for safe agentic programming.
