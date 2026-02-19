# push_swap
![Language](https://img.shields.io/badge/Language-C-blue)
![Score](https://img.shields.io/badge/Score-125%2F100-brightgreen)

<p>A stack-based sorting project focused on algorithmic efficiency.</p>

---

## Table of Contents
- [Overview](#overview)
- [Program](#program)
- [Operations](#operations)
- [Algorithm](#algorithm)
- [Bonus Part](#bonus-part)
- [Author](#author)

---

## Overview

The goal of push_swap is to sort a list of integers using two stacks and a limited set of operations.

The program outputs the smallest possible sequence of instructions that sorts the numbers in ascending order. The emphasis is on efficiency — minimizing the total number of operations.

---

## Program

The program is executed as follows:

```bash
./push_swap [list of integers]
```

Example:

```bash
./push_swap 2 1 3 6 5 8
```

The program prints a sequence of stack operations to `stdout`. When executed, these operations must leave stack A sorted in ascending order.

Input validation includes:
- Handling multiple arguments
- Detecting non-integer values
- Detecting duplicates
- Handling integer overflow
- Proper error management

---

## Operations

The allowed operations are:

| Operation | Description |
| :--- | :--- |
| `sa` | Swap the first two elements of stack A |
| `sb` | Swap the first two elements of stack B |
| `ss` | `sa` and `sb` simultaneously |
| `pa` | Push the top element from B to A |
| `pb` | Push the top element from A to B |
| `ra` | Rotate stack A (first element becomes last) |
| `rb` | Rotate stack B |
| `rr` | `ra` and `rb` simultaneously |
| `rra` | Reverse rotate stack A |
| `rrb` | Reverse rotate stack B |
| `rrr` | `rra` and `rrb` simultaneously |

Only these operations may be used to achieve a sorted stack.

---

## Algorithm

The implementation follows a K-sort–inspired strategy.

Values are first indexed to simplify comparisons. Elements from stack A are pushed to stack B in controlled ranges, keeping smaller values grouped together and larger values grouped together. This creates a structured distribution in stack B.

Once all elements are in stack B, the algorithm repeatedly pushes the largest available value back to stack A. By always selecting the current maximum, stack A is rebuilt in sorted order from top to bottom.

This approach balances partitioning and controlled reconstruction, aiming to reduce unnecessary rotations and total move count.

---

## Bonus Part

The bonus includes a `checker` program:

```bash
./checker [list of integers]
```

The checker reads instructions from `stdin`, executes them, and verifies whether stack A is sorted.

It outputs:
- `OK` if sorted
- `KO` if not sorted
- `Error` on invalid input or instructions

---

## Author
- **Name:** Daniel Zamora
- **GitHub:** [tekuron](https://github.com/tekuron)
- **42 Intra:** [danzamor](https://profile-v3.intra.42.fr/users/danzamor)
- **School:** 42
