CC      := gcc
CFLAGS  := -Wall -Werror -Wextra -pedantic -std=gnu89
NAME    := test

SRCS    := 0-print_dlistint.c \
           1-dlistint_len.c \
           2-add_dnodeint.c \
           3-add_dnodeint_end.c \
           4-free_dlistint.c \
           5-get_dnodeint.c \
           6-sum_dlistint.c \
           7-insert_dnodeint.c \
           8-delete_dnodeint.c

OBJS    := $(SRCS:.c=.o)
DEPS    := lists.h

.PHONY: all help objects clean fclean re run0 run1 run2 run3 run4 run5 run6 run7 run8

all: objects
	@echo "Built object files for: $(SRCS)"

help:
	@echo "Targets:"
	@echo "  all        - compile all task sources to .o (no link)"
	@echo "  run0..run8 - build and run each task with its matching X-main.c"
	@echo "  clean      - remove object files"
	@echo "  fclean     - remove objects and '$(NAME)'"
	@echo "  re         - clean + rebuild objects"

objects: $(OBJS)

%.o: %.c $(DEPS)
	$(CC) $(CFLAGS) -c $< -o $@

run0: 0-main.c 0-print_dlistint.c
	$(CC) $(CFLAGS) 0-main.c 0-print_dlistint.c -o $(NAME)
	./$(NAME)

run1: 1-main.c 1-dlistint_len.c
	$(CC) $(CFLAGS) 1-main.c 1-dlistint_len.c -o $(NAME)
	./$(NAME)

run2: 2-main.c 2-add_dnodeint.c 0-print_dlistint.c 4-free_dlistint.c
	$(CC) $(CFLAGS) 2-main.c 2-add_dnodeint.c 0-print_dlistint.c 4-free_dlistint.c -o $(NAME)
	./$(NAME)

run3: 3-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c
	$(CC) $(CFLAGS) 3-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c -o $(NAME)
	./$(NAME)

run4: 4-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c
	$(CC) $(CFLAGS) 4-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c -o $(NAME)
	./$(NAME)

run5: 5-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 5-get_dnodeint.c
	$(CC) $(CFLAGS) 5-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 5-get_dnodeint.c -o $(NAME)
	./$(NAME)

run6: 6-main.c 3-add_dnodeint_end.c 4-free_dlistint.c 6-sum_dlistint.c
	$(CC) $(CFLAGS) 6-main.c 3-add_dnodeint_end.c 4-free_dlistint.c 6-sum_dlistint.c -o $(NAME)
	./$(NAME)

run7: 7-main.c 2-add_dnodeint.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 7-insert_dnodeint.c
	$(CC) $(CFLAGS) 7-main.c 2-add_dnodeint.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 7-insert_dnodeint.c -o $(NAME)
	./$(NAME)

run8: 8-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 8-delete_dnodeint.c
	$(CC) $(CFLAGS) 8-main.c 3-add_dnodeint_end.c 0-print_dlistint.c 4-free_dlistint.c 8-delete_dnodeint.c -o $(NAME)
	./$(NAME)

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
