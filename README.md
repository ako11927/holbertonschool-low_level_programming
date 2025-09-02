# Low-Level Programming in C

This repository contains projects for Holberton School's low-level programming track.  
This module focuses on **pointers, arrays, and strings**.

## Learning Objectives
- What are pointers and how to use them
- What are arrays and how to use them
- Differences between pointers and arrays
- How to use strings and manipulate them
- Scope of variables

## Requirements
- Ubuntu 20.04, `gcc` flags: `-Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style for code and documentation
- No global variables
- No standard library calls (except `_putchar`); task 8 may use `printf`
- Each file ends with a newline

## Files in `pointers_arrays_strings/`

- `pointers_arrays_strings/0-reset_to_98.c` — updates the value of an int via pointer to 98
- `pointers_arrays_strings/1-swap.c` — swaps the values of two integers
- `pointers_arrays_strings/100-atoi.c` — converts a string to an integer
- `pointers_arrays_strings/2-strlen.c` — returns the length of a string
- `pointers_arrays_strings/3-puts.c` — prints a string followed by a newline
- `pointers_arrays_strings/4-print_rev.c` — prints a string in reverse
- `pointers_arrays_strings/5-rev_string.c` — reverses a string in place
- `pointers_arrays_strings/6-puts2.c` — prints every other character of a string
- `pointers_arrays_strings/7-puts_half.c` — prints the second half of a string
- `pointers_arrays_strings/8-print_array.c` — prints n elements of an int array (uses printf)
- `pointers_arrays_strings/9-strcpy.c` — copies a string to a buffer (including '\0')

## Build examples
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c pointers_arrays_strings/0-reset_to_98.c -o 0-98
./0-98
