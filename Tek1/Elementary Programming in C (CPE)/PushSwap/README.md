<p align="center"><img src="../../../images/push_swap.jpg" width="400" alt="PushSwap img"></p>

# Push Swap

![Badge Mark](https://img.shields.io/badge/Module%20Mark-A-%2372FA08.svg?&style=for-the-badge&logoColor=black)

## Overview

The goal of this project is to return in the output the easiest way to sort a list of integers (give as argument) as quickly as possible with any algorithm you want.

It was a good learning project because I had the opportunity to discover many sorting algorithms and the [Big O notation].

[Big O notation]: (https://en.wikipedia.org/wiki/Big_O_notation)

## How to use

#### Example
```bash
./push_swap 2 1 3 6 5 8
>sa pb pb pb sa pa pa pa
```

#### Possible Instructions
```
• sa
swap the first two elements of l_a (nothing will happen if there aren’t enough elements).
• sb
swap the first two elements of l_b (nothing will happen if there aren’t enough elements).
• sc
sa and sb at the same time.
• pa
take the first element from l_b and move it to the first position on the l_a list (nothing will happen if
l_b is empty).
• pb
take the first element from l_a and move it to the first position on the l_b list (nothing will happen if
l_a is empty).
• ra
rotate l_a toward the beginning, the first element will become the last.
• rb
rotate l_b toward the beginning, the first element will become the last.
• rr
ra and rb at the same time.
• rra
rotate l_a toward the end, the last element will become the first.
• rrb
rotate l_b toward the end, the last element will become the first.
• rrr
rra and rrb at the same time.
```
