CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -pedantic -std=gnu89
INCDIR  := .
SRCS    := 0-puts_recursion.c 1-print_rev_recursion.c 2-strlen_recursion.c \
           3-factorial.c 4-pow_recursion.c 5-sqrt_recursion.c 6-is_prime_number.c

T_DIR   := tests
EXECS   := 0-puts_recursion 1-print_rev_recursion 2-strlen_recursion \
           3-factorial 4-pow 5-sqrt 6-prime

.PHONY: all clean fclean re
all: $(EXECS)

0-puts_recursion: 0-puts_recursion.c $(T_DIR)/0-main.c $(T_DIR)/_putchar.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

1-print_rev_recursion: 1-print_rev_recursion.c $(T_DIR)/1-main.c $(T_DIR)/_putchar.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

2-strlen_recursion: 2-strlen_recursion.c $(T_DIR)/2-main.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

3-factorial: 3-factorial.c $(T_DIR)/3-main.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

4-pow: 4-pow_recursion.c $(T_DIR)/4-main.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

5-sqrt: 5-sqrt_recursion.c $(T_DIR)/5-main.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

6-prime: 6-is_prime_number.c $(T_DIR)/6-main.c main.h
	$(CC) $(CFLAGS) -I$(INCDIR) $^ -o $@

clean:
	rm -f *.o $(T_DIR)/*.o

fclean: clean
	rm -f $(EXECS)

re: fclean all
