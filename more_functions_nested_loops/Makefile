CC = gcc
CFLAGS = -Wall -Werror -Wextra -pedantic -std=gnu89

SRC_COMMON = _putchar.c 0-isupper.c 1-isdigit.c 2-mul.c \
             3-print_numbers.c 4-print_most_numbers.c 5-more_numbers.c \
             6-print_line.c 7-print_diagonal.c 8-print_square.c 10-print_triangle.c

.PHONY: all test fizz clean

all: test fizz

test: $(SRC_COMMON) test_all.c main.h
	$(CC) $(CFLAGS) $(SRC_COMMON) test_all.c -o test_all

fizz: 9-fizz_buzz.c
	$(CC) $(CFLAGS) 9-fizz_buzz.c -o 9-fizz_buzz

clean:
	rm -f test_all 9-fizz_buzz
