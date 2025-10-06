# Singly Linked Lists

## Description
This project is part of the Holberton School low-level programming track.  
It focuses on **singly linked lists** — one of the fundamental data structures in C.

You will learn how to:
- Build and manipulate linked lists
- Understand memory allocation (`malloc` / `free`)
- Work with `struct` and pointers
- Compare linked lists vs arrays

---

## Requirements
- Allowed editors: `vi`, `vim`, `emacs`
- All files compiled on **Ubuntu 20.04 LTS** using:
  ```bash
  gcc -Wall -Werror -Wextra -pedantic -std=gnu89
---

## Task 6: The Hare and the Tortoise 🐢

**File:** `100-first.c`

### Description:
This file contains a function that prints a specific message *before the main function executes*, using GCC’s `__attribute__((constructor))`.

### Function Used:
```c
void __attribute__ ((constructor)) first(void);
