# Push_swap

## About

**Push_swap** is a sorting algorithm project that challenges you to sort a stack of integers using a limited set of operations while minimizing the number of moves. This project is a great introduction to algorithmic complexity and optimization.

## Objectives

- Implement an efficient sorting algorithm using stack operations.
- Minimize the number of operations needed to sort a given set of numbers.
- Manage memory allocation and handle errors correctly.
- Understand sorting complexity and algorithm optimization.

## Features

- Sorting algorithm using only stack-based operations.
- Error handling for invalid inputs and duplicate numbers.
- Efficient sorting with a goal of minimal operations.
- Bonus: A `checker` program to verify sorting correctness.

## Dependencies

- A C compiler (`gcc` or `clang`)
- `make` (for building the project)
- `libft` (custom C library for helper functions)

## Installation

Clone the repository and compile the program using `make`:

```sh
 git clone https://github.com/Nabil080/push_swap
 cd push_swap
 make
```

## Usage

Run the program with multiple integer arguments to sort:

```sh
./push_swap 4 67 3 87 23
```

It will output a sequence of operations that sorts the given numbers using the allowed stack operations.

To check if the generated sequence sorts the numbers correctly, use the `checker` program:

```sh
make checker
./push_swap 4 67 3 87 23 | ./checker 4 67 3 87 23
```

## Available Operations

- `sa` / `sb` / `ss` : Swap the first two elements of stack A / B / both.
- `pa` / `pb` : Push the top element from one stack to the other.
- `ra` / `rb` / `rr` : Rotate a stack (shift all elements up by 1).
- `rra` / `rrb` / `rrr` : Reverse rotate a stack (shift all elements down by 1).

## Cleaning Up

To remove compiled files, run:

```sh
make clean
```

To completely remove all binaries and object files:

```sh
make fclean
```
