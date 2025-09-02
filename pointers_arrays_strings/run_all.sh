#!/usr/bin/env bash
# Compile & run every task with GNU89 + Holberton flags

CFLAGS="-Wall -Werror -Wextra -pedantic -std=gnu89"

run() {
  local exe="$1"; shift
  echo "===== Building $exe ====="
  if gcc $CFLAGS "$@" -o "$exe"; then
    echo "--- Running $exe ---"
    ./"$exe"
    echo
  else
    echo "Build failed for $exe ❌"
    echo
  fi
}

# Tasks (include _putchar.c where needed)
run 0-98      0-main.c 0-reset_to_98.c
run 1-swap    1-main.c 1-swap.c
run 2-strlen  2-main.c 2-strlen.c
run 3-puts    _putchar.c 3-main.c 3-puts.c
run 4-print   _putchar.c 4-main.c 4-print_rev.c
run 5-rev     5-main.c 5-rev_string.c
run 6-puts2   _putchar.c 6-main.c 6-puts2.c
run 7-half    _putchar.c 7-main.c 7-puts_half.c
run 8-array   8-main.c 8-print_array.c
run 9-strcpy  9-main.c 9-strcpy.c
run 100-atoi  100-main.c 100-atoi.c
