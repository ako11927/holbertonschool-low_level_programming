# 0x0F. Variadic functions

Implementations of utility functions that use C variadic arguments (`stdarg.h`).

## Requirements
- OS: Ubuntu 20.04 LTS
- Compiler: `gcc -Wall -Werror -Wextra -pedantic -std=gnu89`
- Editors: `vi`, `vim`, `emacs`
- Betty style: `betty-style.pl` and `betty-doc.pl`
- No global variables
- ≤ 5 functions per file
- Allowed C stdlib funcs: `malloc`, `free`, `exit`
- Allowed macros: `va_start`, `va_arg`, `va_end`
- `_putchar` allowed (checker provides it)
- All prototypes in `variadic_functions.h`
- Each file ends with a newline

> Note: Per task specs, `printf` is allowed where indicated (Tasks 1–3).

## Files
- `variadic_functions.h` — prototypes and includes.
- `0-sum_them_all.c` — `int sum_them_all(const unsigned int n, ...);`
  - Returns the sum of all parameters (returns `0` if `n == 0`).
- `1-print_numbers.c` — `void print_numbers(const char *separator, const unsigned int n, ...);`
  - Prints integers separated by `separator` (ignored if `NULL`) and ends with newline.
- `2-print_strings.c` — `void print_strings(const char *separator, const unsigned int n, ...);`
  - Prints strings separated by `separator`; prints `(nil)` for `NULL` strings; newline at end.
- `3-print_all.c` — `void print_all(const char * const format, ...);`
  - Handles format chars: `c` (char), `i` (int), `f` (float/double), `s` (char*).  
    Ignores unknown specifiers; prints `(nil)` for `NULL` strings; newline at end.  
    Conforms to task constraints (no `for`, no `else`, ≤ 2 `while`, ≤ 2 `if`, ≤ 9 vars).

## Compile (with the provided example mains)
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c 0-sum_them_all.c -o a
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 1-main.c 1-print_numbers.c -o b
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 2-main.c 2-print_strings.c -o c
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 3-main.c 3-print_all.c -o d
