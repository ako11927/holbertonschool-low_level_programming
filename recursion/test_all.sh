#!/usr/bin/env bash
set -e
cd "$(dirname "$0")"
for exe in 0-puts_recursion 1-print_rev_recursion 2-strlen_recursion 3-factorial 4-pow 5-sqrt 6-prime; do
  echo "== $exe =="
  ./"$exe"
done
