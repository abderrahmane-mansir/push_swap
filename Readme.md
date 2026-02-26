*This project has been created as part of the 42 curriculum by **amansir**.*

# push_swap
Because `swap_push` doesn’t feel as natural

## Description

push_swap is a sorting algorithm project designed for the 42 curriculum. The goal is to sort a stack of integers using a limited set of operations (push, swap, rotate, reverse rotate) and to do so with the minimum number of moves. The project emphasizes algorithmic efficiency, data structure manipulation, and clean, robust C code.

The program receives a list of integers as arguments, builds two stacks (A and B), and sorts stack A using only allowed operations. The output is a sequence of instructions that, when executed, will sort the stack.

## Instructions

### Compilation

To compile the project, run:

```
make
```

This will produce the executable `push_swap`.

### Usage

Run the program with a list of integers:

```
./push_swap 3 2 1 0 -5
```

The program will output the sequence of operations required to sort the stack.

### Testing

You can use the provided `main.c` for custom tests, or pipe the output to a checker program to validate correctness and efficiency.

### Allowed Operations
- `sa`, `sb`, `ss`: swap the top two elements of stack A, B, or both
- `pa`, `pb`: push the top element from one stack to the other
- `ra`, `rb`, `rr`: rotate stack A, B, or both upwards
- `rra`, `rrb`, `rrr`: rotate stack A, B, or both downwards

## Resources

- [Radix Sort Algorithm](https://en.wikipedia.org/wiki/Radix_sort)
- [Linked List Data Structures](https://en.wikipedia.org/wiki/Linked_list)
- [Linked List Manupulation](https://www.geeksforgeeks.org/c/linked-list-in-c/)

