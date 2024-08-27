
# Push_swap

The Push_swap project is a sorting algorithm exercise that requires sorting a stack of integers using a limited set of instructions with the minimum number of operations. The goal is to create a C program named push_swap that outputs the shortest sequence of commands to sort a given stack.

## Project Objectives:
Develop a sorting algorithm focusing on minimizing operational complexity.
Implement and practice fundamental C programming skills, including memory management and adherence to the project's coding standards.
Understand and manage algorithmic complexity and performance optimization.

## Program Rules:
Two stacks are used: stack a (initially contains integers) and stack b (initially empty).
The objective is to sort stack a in ascending order using the following operations:
- `sa`, `sb`, `ss`: Swap the first two elements of stacks a, b, or both.
- `pa`, `pb`: Push the first element of stack b to a or vice versa.
- `ra`, `rb`, `rr`: Rotate stack a, b, or both upward.
- `rra`, `rrb`, `rrr`: Reverse rotate stack a, b, or both downward.

## Error Handling:
- The program must handle errors gracefully, printing "Error" followed by a newline if any issues arise (e.g., invalid input, duplicates, non-integer values).
## Bonus Part - Checker Program:
- A `checker` program can be implemented to verify that the sequence of instructions correctly sorts the input stack.
- This program reads from standard input, executes the provided instructions, and checks if stack `a` is sorted and stack `b` is empty.

## Requirements:
- Implement the `push_swap` program using C.
- Ensure no memory leaks and handle all errors properly.
- Create a Makefile with standard rules to compile the project (`NAME`, `all`, `clean`, `fclean`, `re`).

The challenge is to achieve optimal sorting with the least number of operations, making the Push_swap project an excellent opportunity to enhance your algorithmic skills and C programming abilities.







## Running Tests
Compile the Project:

First, ensure your project is compiled by running:

```
make
```
Predefined Tests
Use the predefined Makefile targets to run tests with different sets of random numbers:

- `test2`: Test with 2 random numbers.
- `test3`: Test with 3 random numbers.
- `test5`: Test with 5 random numbers.
- `test100`: Test with 100 random numbers.
- `test500`: Test with 500 random numbers.
- `test1000`: Test with 1000 random numbers.

## Running a Specific Test
To run a test with 100 random numbers, use:

```
make test100
```

This command generates 100 random numbers, sorts them using `push_swap`, verifies the sorting with `checker_linux`, and displays the number of instructions used.

## Understanding the Results
`OK`: The sequence of instructions successfully sorted the numbers.

`KO`: The numbers are not sorted correctly, indicating a potential issue in push_swap.

## Difference Between `checker_linux` and `checker`
- `checker_linux`: For the mandatory part of the project, specific to Linux. It checks if `push_swap` correctly sorts the numbers.
- `checker`: For the bonus part, offering similar or enhanced functionality. You need to implement this checker for the bonus, and it should perform similarly or better than `checker_linux`.
