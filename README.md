<div align="center">

# DSA-CPP-STRIVER

### Working through Striver's A2Z DSA course in C++ — day by day, every formulation written out.

![C++](https://img.shields.io/badge/C%2B%2B-STL-00599C?logo=cplusplus&logoColor=white)
![Problems Solved](https://img.shields.io/badge/Problems%20Solved-250%2B-success)
![Daily Practice](https://img.shields.io/badge/Consistent%20Practice-60%2B%20days-orange)
![Last Commit](https://img.shields.io/github/last-commit/harshiljain2911/DSA-CPP-STRIVER)

</div>

---

**250+ C++ solutions across 60+ days of consistent daily practice**, following the
[Striver A2Z DSA course](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2)
progression — from sorting fundamentals through a complete graph track to a
20-day dynamic-programming deep dive.

## Repository Highlights

- 🎯 **Curriculum-driven** — follows the A2Z sheet end to end: sorting → arrays →
  binary search → strings → stacks → linked lists → trees → graphs → DP.
- 🧠 **Three formulations per DP problem** — memoization, tabulation, and
  space-optimisation written as separate solutions across a 20-day DP track.
- 🕸️ **Complete graph coverage** — BFS/DFS, topological sort, Dijkstra,
  Bellman-Ford, Floyd-Warshall, Prim's MST, and Disjoint Set Union.
- 📅 **Daily consistency** — one focused session per day, logged as `dayN`,
  for 60+ days and counting.
- ✍️ **Alternative approaches preserved side by side** — multiple solutions to
  the same problem are kept wherever applicable (`*_mine`, `*_approach_II`).

## Purpose

To build interview-ready command of data structures and algorithms by working
through a single rigorous curriculum completely, rather than sampling problems
at random — in C++ with STL — to the point where I can:

1. Recognize the underlying pattern of an unseen problem.
2. State the brute-force solution and its complexity immediately.
3. Derive the optimal approach and justify its time/space trade-offs.

This repository is the working record of that process, and my revision reference
before contests and interviews.

## Repository Structure

```
DSA-CPP-STRIVER/
├── day1/                   ← one folder per practice day
│   ├── bubble_sort.cpp
│   ├── selection_sort.cpp
│   └── ...
├── day2/
├── ...
└── dayN/                   ← latest practice day
```

| Naming convention | Meaning |
| :--- | :--- |
| `(BRUTE)` / `(OPTIMAL)` | multiple approaches to the same problem |
| `_memoized` / `_tabulation` / `_space_optimised` | the three classic DP formulations |
| `_approach_II` | an alternative solution to a problem already solved |
| `_mine` | my own alternative approach to the same problem |

## Topic-wise Navigation

| Topic | Where | Representative problems |
| :--- | :--- | :--- |
| Sorting & Array Fundamentals | [day 1](day1) – 5 | Bubble/Selection Sort · Rotate Array · Kadane's Max Subarray |
| Binary Search | [day 6](day6) – 8 | Lower Bound · Rotated Sorted Array · Peak Element |
| Strings | [day 9](day9) – 10, 16 – 18 | Reverse Words · Isomorphic Strings · Roman to Integer · atoi |
| Sliding Window & Prefix Sum | [day 11](day11) – 13 | Max Consecutive Ones III · Binary Subarrays With Sum · Card Points |
| Monotonic Stack | [day 13](day13) – 16 | NGE/NSE/PGE/PSE · Asteroid Collision · Sum of Subarray Minimums · Remove K Digits |
| Linked Lists | [day 19](day19) – 21 | Reverse LL · Detect Cycle · Intersection · Sort LL · Add Two Numbers |
| Greedy | [day 22](day22) – 23 | Jump Game I/II · Candy · Lemonade Change · Koko Eating Bananas |
| Binary Trees | [day 26](day26) – 30 | Traversals (recursive + iterative) · Diameter · Max Path Sum · Vertical Order |
| Binary Search Trees | [day 31](day31) – 33 | Validate BST · LCA · BST Iterator · Recover BST · Largest BST |
| Graphs — BFS/DFS & Toposort | [day 24](day24) – 25, 34 – 36 | Rotting Oranges · Course Schedule I/II · Alien Dictionary · Safe Nodes |
| Graphs — Shortest Paths | [day 37](day37) – 38 | Dijkstra · Bellman-Ford · Floyd-Warshall · Network Delay Time |
| Graphs — MST & DSU | [day 39](day39) – 41 | Prim's Algorithm · Disjoint Set · Accounts Merge · Islands II · Swim in Rising Water |
| Bit Manipulation & Math | [day 42](day42) | Power Set · Min Bit Flips · Divide Two Integers · Count Primes |
| DP — 1-D & Grids | [day 43](day43) – 45 | Climbing Stairs · Frog Jump · House Robber · Ninja Training · Unique Paths I/II |
| DP — Subsets & Knapsack | [day 46](day46) – 53 | Subset Sum · Partition Min Difference · Coin Change I/II · Target Sum · Unbounded Knapsack · Rod Cutting |
| DP — Strings | [day 54](day54) – 58 | LCS · Longest Common Substring · Edit Distance · Wildcard Matching |
| DP — Stocks | [day 58](day58) – 60 | Buy & Sell Stock II/III/IV · Cooldown · Transaction Fee |
| DP — LIS Family | [day 60](day60) – 62 | LIS (4 ways) · Printing LIS · Largest Divisible Subset · Longest Bitonic Subsequence |

## Progress Tracker

**250+ solutions · 60+ practice days · updated daily**

- [x] Sorting & Array Fundamentals
- [x] Binary Search
- [x] Strings
- [x] Sliding Window & Prefix Sum
- [x] Monotonic Stack
- [x] Linked Lists
- [x] Greedy
- [x] Binary Trees & BSTs
- [x] Graphs — BFS/DFS, Topological Sort
- [x] Graphs — Dijkstra, Bellman-Ford, Floyd-Warshall
- [x] Graphs — MST & Disjoint Set Union
- [x] Bit Manipulation
- [x] DP — 1-D, grids, subsets/knapsack, strings, stocks, LIS
- [ ] Heaps & Priority Queues
- [ ] Tries
- [ ] Advanced Strings (KMP / Z-function)
- [ ] Segment Trees & advanced structures

## Complexity Notation Legend

| Notation | Name | Intuition |
| :--- | :--- | :--- |
| O(1) | Constant | same cost regardless of input size |
| O(log n) | Logarithmic | halves the search space each step |
| O(n) | Linear | touches each element once |
| O(n log n) | Linearithmic | efficient sorting, divide & conquer |
| O(n²) | Quadratic | nested loops over the input |
| O(2ⁿ) | Exponential | explores every subset |

Where a problem has multiple solution files, they are ordered by decreasing
complexity — the brute-force file shows the idea, the optimal file the best bound.

## Study Strategy

1. **One curriculum, completely** — every step of the A2Z sheet is worked through
   in order; no cherry-picking the comfortable topics.
2. **Convert, don't memorize, DP** — writing memoization, tabulation, and
   space-optimisation separately internalizes the transformation between them.
3. **Alternative approaches are preserved side by side wherever applicable** —
   different solutions to the same problem stay in the repository together.
4. **Spaced revision** — dedicated revision days revisit earlier topics after a gap.

## Resources

- [Striver's A2Z DSA Course](https://takeuforward.org/strivers-a2z-dsa-course/strivers-a2z-dsa-course-sheet-2) — the curriculum this repository follows
- [LeetCode](https://leetcode.com) — primary problem source
- [cppreference](https://en.cppreference.com) — STL containers & algorithms reference
