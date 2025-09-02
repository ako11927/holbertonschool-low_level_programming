#!/usr/bin/env bash
# Generate a README.md for Holberton low-level project (root-level)

set -euo pipefail

PROJECT_DIR="pointers_arrays_strings"
OUTFILE="README.md"

# Collect files (sorted), ignore mains & helper scripts
mapfile -t CFILES < <(find "$PROJECT_DIR" -maxdepth 1 -type f -name "*.c" \
  ! -name "*-main.c" ! -name "*_main.c" ! -name "_putchar.c" \
  | sort)

# Title & intro
cat > "$OUTFILE" <<'HDR'
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
HDR

# Files section
echo "" >> "$OUTFILE"
echo "## Files in \`$PROJECT_DIR/\`" >> "$OUTFILE"
echo "" >> "$OUTFILE"

if ((${#CFILES[@]}==0)); then
  echo "_No C files found yet. Add your source files to \`$PROJECT_DIR/\`._" >> "$OUTFILE"
else
  for f in "${CFILES[@]}"; do
    base="$(basename "$f")"
    case "$base" in
      0-reset_to_98.c)   desc="updates the value of an int via pointer to 98" ;;
      1-swap.c)          desc="swaps the values of two integers" ;;
      2-strlen.c)        desc="returns the length of a string" ;;
      3-puts.c)          desc="prints a string followed by a newline" ;;
      4-print_rev.c)     desc="prints a string in reverse" ;;
      5-rev_string.c)    desc="reverses a string in place" ;;
      6-puts2.c)         desc="prints every other character of a string" ;;
      7-puts_half.c)     desc="prints the second half of a string" ;;
      8-print_array.c)   desc="prints n elements of an int array (uses printf)" ;;
      9-strcpy.c)        desc="copies a string to a buffer (including '\\0')" ;;
      100-atoi.c)        desc="converts a string to an integer" ;;
      *)                 desc="source file" ;;
    esac
    printf -- "- \`%s/%s\` — %s\n" "$PROJECT_DIR" "$base" "$desc" >> "$OUTFILE"
  done
fi

cat >> "$OUTFILE" <<'FOOT'

## Build examples
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 0-main.c pointers_arrays_strings/0-reset_to_98.c -o 0-98
./0-98
