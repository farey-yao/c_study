# Week 1: K&R Chapters 1–3

This directory contains C exercises based on Chapters 1–3 of *The C Programming Language* (K&R, 2nd edition). The goal is to complete these chapters and gain confidence with basic C syntax, expressions, and control flow.

## In Scope

- Chapter 1: program structure, standard input/output, functions, variables, and simple text processing.
- Chapter 2: integer and floating-point types, constants, operators, expressions, conversions, and bitwise operators.
- Chapter 3: `if`/`else`, `switch`, loops, `break`, `continue`, and basic functions.

## Exercise Rules

- Teach the user how to develop each program step by step instead of writing the complete solution directly.
- Explain the relevant C concepts, ask the user to write or revise the code, and provide hints or small examples when needed.
- Review code written by the user and point out specific improvements, but do not replace it with a finished program unless the user explicitly asks for the complete solution.
- Keep every exercise self-contained in one `.c` file with a descriptive filename.
- Begin programs with `#include <stdio.h>` when they use standard input or output.
- Use `int main(void)` and return `0` from successful programs.
- Favor clear variable names and straightforward control flow over compact tricks.
- Add a short comment only when it explains the exercise or a non-obvious choice; do not comment every line.
- For text-processing programs, test empty input, a single line, multiple lines, spaces, tabs, and end-of-file behavior where relevant.
- For numeric programs, include small sample inputs or expected values in a comment or in the final report.

## Boundaries for This Week

- Do not introduce pointers, dynamic memory allocation, structs, file I/O, GMP, multi-file layouts, or a Makefile unless the user explicitly asks.
- Do not use non-standard libraries to replace concepts that the exercise is meant to practice.
- Avoid premature optimization. Correct, readable code is the priority.

## Verification

- Do not compile programs yourself. Ask the user to run the compiler and share any warnings or errors.
- Give the user this compilation command for changed programs:

  ```sh
  gcc -std=c11 -Wall -Wextra -Wpedantic filename.c -o filename
  ```

- Guide the user through at least one representative test after they compile, and help them understand and fix all newly introduced compiler warnings.
