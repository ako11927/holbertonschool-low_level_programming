# 0x0D. C - Structures, typedef

This project covers defining and using `struct` in C, and creating aliases with `typedef`.

## Learning Objectives
- What structures are, when/why/how to use them
- How to use `typedef`

## Requirements
- Ubuntu 20.04, `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Betty style
- Allowed C lib funcs: `printf`, `malloc`, `free`, `exit`
- No global variables; ≤ 5 functions per file
- Header files must be include-guarded

## Files
- `dog.h` — struct definition and `dog_t` typedef, function prototypes
- `1-init_dog.c` — initialize a `struct dog`
- `2-print_dog.c` — print a `struct dog` (handles NULL fields)
- `4-new_dog.c` — create a new `dog_t` (copies `name` and `owner`)
- `5-free_dog.c` — free a `dog_t`

## Compile examples
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-init_dog.c -o b
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-print_dog.c -o c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 4-main.c 4-new_dog.c -o e
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 5-main.c 5-free_dog.c 4-new_dog.c -o f

