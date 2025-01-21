# C++ Module 09: Exploring Different `std::container` Implementations

## Table of Contents
- [Overview](#overview)
- [Exercises](#exercises)
  - [1. Ex00: Bitcoin Exchange](#1-ex00-bitcoin-exchange)
  - [2. Ex01: Reverse Polish Notation (RPN) Calculator](#2-ex01-reverse-polish-notation-rpn-calculator)
  - [3. Ex02: Sorting Algorithm: Ford-Johnson Merge-Insertion Sort](#3-ex02-sorting-algorithm-ford-johnson-merge-insertion-sort)
- [How to Use](#how-to-use)
- [Learning Outcomes](#learning-outcomes)

## Overview
This module focuses on utilizing various `std::container` types in C++ to solve distinct problems. Each exercise is designed to emphasize the unique characteristics and features of specific containers while implementing practical algorithms.

## Exercises

### 1. Ex00: Bitcoin Exchange
**Objective:**
Implement a system to track and evaluate Bitcoin exchange rates over time. The goal is to efficiently handle historical data, perform lookups, and calculate exchange values.

**Key Features:**
In this exercise, I used an std::map with a custom comparison function, std::greater<std::string>, to initialize the container in reverse order, storing dates from the most recent to the oldest. This approach ensures that each insertion places the largest date first, maintaining an efficient descending order. During user queries, I leveraged the lower_bound method to locate the closest smaller or equal date, returning accurate results based on the user's request. This implementation effectively avoids the insertion of non-existent dates (and leap years), ensuring data consistency while optimizing lookup performance.

**How To Use:**
Provide a file as input. The input file should follow this format:
```bash
date | value
2011-01-03 | 3
2011-01-03 | 2
2011-01-03 | 1
2011-01-03 | 1.2
2011-01-09 | 1
2012-01-11 | -1
2001-42-42
2012-01-11 | 1
2012-01-11 | 2147483648
```

Example usage:

```bash
./btc <input_file>
```


### 2. Ex01: Reverse Polish Notation (RPN) Calculator

**Objective:** Create a calculator that evaluates expressions written in Reverse Polish Notation (postfix notation).

**Key Features:**

- This exercise uses `std::stack`. Basic stack operations such as `pop`, `top`, and `push` are utilized.
- At the end of each call, the program performs a syntax check to ensure correctness. If there are too few or too many numbers or insufficient operators, an error message will appear.
- The program supports the following operators: `'*'`, `'/'`, `'+'`, and `'-'`.
- Only numbers between `0` and `9`, separated by spaces (including all whitespaces), are accepted as input.
- A check prevents division by zero, and an exception is thrown if such a case occurs.

**How to Use:**

To run the RPN Calculator, provide an input file containing an RPN expression. Each line in the file should represent a valid postfix expression to evaluate.

Example usage:

```bash
./rpn "5 1 2 + 4 * + 3 -"
```

Input text format example:

```
3 4 +
5 1 2 + 4 * + 3 -
7 8 * 3 /
```
### 3. Ex02: Sorting Algorithm: Ford-Johnson Merge-Insertion Sort
**Objective:**

This project implements the Ford-Johnson sorting algorithm, based on the algorithm described in The Art of Computer Programming by Donald E. Knuth. This sorting method combines a merge-sort technique with binary insertion, optimized using Jacobsthal numbers. The goal is to achieve a time complexity that doesn’t exceed O(n log n), with the worst case being O(n log₂ n).
Algorithm Overview

The Ford-Johnson sorting algorithm works by recursively merging pairs of elements in a sequence and performing binary insertion based on the Jacobsthal sequence. The main advantage of this approach is that it maintains O(n log n) time complexity in the worst case.

**Key Concepts:**


Merge Sort: The algorithm uses a modified merge sort to recursively build pairs.

Binary Insertion: As elements are recursively merged, they are inserted into a sorted sequence using binary insertion.

Jacobsthal Numbers: These numbers are used to guide the binary insertion steps, optimizing the process of merging pairs.

**Workflow:**
1. Initialization

The algorithm begins by initializing pairs of elements into a structure. Each pair consists of:

1. int leader: An integer leader.
2. RecursivePair * first: A pointer to the larger pair.
3. RecursivePair *second: A pointer to the second, smaller pair.

These pairs are recursively built until a single pair remains.
2. Recursive Pair Construction

The algorithm recursively builds pairs, where each pair consists of two sub-pairs.
The process continues recursively, breaking down the elements into smaller sub-pairs until only one pair remains.

3. Insertion Using Jacobsthal Sequence

At each recursion level, after the pair is fully built:

- The "second" element of each pair (B's by the book) is inserted into the main chain of ordered leaders.
- The leader remains in place while the second element is placed accordingly, maintaining order.
- NULL is placed in the first number of each pair to track which pairs are already ordered.

The process continues recursively, with each pair inserted at the appropriate position in the chain.

4. Finalizing the Recursion

The final step in each recursion level involves "wrapping" the pairs. This means the leader and the largest pair are paired together to prepare for the next recursion level. This final step ensures that the pairs are structured correctly for future merges.
**Challenges Faced:**

   - Pair Structure: Initially, I tried using `<utility>` pairs, but encountered a significant issue during recursive pair building. Since each pair consisted of two other pairs, which are all template parameters, the compiler failed to resolve the full definition of the pair template at compile time. This led to excessive recursion and eventually caused the compiler to crash after approximately 900 iterations. To resolve this, I implemented my own pair-like structure using reseambling like linked lists, which behaves like a chain and avoids this problem.

   - Tracking Jacobsthal Indices: During the binary insertion phase, as new elements are inserted into the main chain, the indices of the Jacobsthal sequence shift. To handle this, I tracked both the previous and current positions in the sequence, along with the index i, to ensure correct placement of elements.

   - Avoiding Shallow Copies: Another challenge was ensuring that recursion returned correctly. To avoid shallow copying of pairs (where pointers might point to the wrong positions), I return a copy of the final pair at each recursion level. This guaranteed that pointers remained valid and pointed to the correct elements.

**Time consumption:**

The Ford-Johnson algorithm is designed to have a time complexity of O(n log n) in the worst case (O(n lon 2n) worst case), which is optimal for a comparison-based sorting algorithm. The recursive structure of the algorithm, combined with binary insertion and the use of Jacobsthal numbers, ensures that the time complexity does not exceed O(n log₂ n), even in the worst case.

Data Structures Used

Two containers are used in this implementation:

- std::vector: A dynamic array that allows for efficient random access using the [] operator.
- std::deque: A double-ended queue, also providing efficient access to elements with the [] operator, and facilitating the alternating between the sequence numbers during merging.

Both containers were chosen because they support direct indexing, which is essential for efficiently navigating and manipulating the elements in the sequence. In large numbers, over few thousands, the vector becomes more efficiant. in smaller numbers it will not have sinificant difference.
Conclusion

The Ford-Johnson algorithm is an interesting and efficient sorting method, particularly when combined with binary insertion using the Jacobsthal sequence. Despite challenges with recursion and pair construction, the final implementation maintains a O(n log n) time complexity and successfully sorts the elements in an optimal manner.

## How to Use
1. Clone this repository:
   ```bash
   git clone <repository-url>
   ```
2. Navigate to the `cpp09` directory:
   ```bash
   cd cpp09
   ```
3. Build the project:
	- inside each excercise directory, run make to compile the files.
   ```bash
   make
   ```

## Learning Outcomes
- Understand the strengths and weaknesses of various `std::container` types.
- Learn to apply appropriate containers to solve specific problems efficiently.
- Develop advanced algorithms using C++ and standard library features.


