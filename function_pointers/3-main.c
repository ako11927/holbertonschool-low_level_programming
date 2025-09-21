#include "3-calc.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * main - Simple calculator entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success (exits with codes on error per spec)
 */
int main(int argc, char *argv[])
{
	int a, b, result;
	int (*f)(int, int);
	char *op;

	if (argc != 4)
	{
		printf("Error\n");
		exit(98);
	}

	op = argv[2];
	f = get_op_func(op);

	if (f == NULL || op[1] != '\0')
	{
		printf("Error\n");
		exit(99);
	}

	a = atoi(argv[1]);
	b = atoi(argv[3]);

	if ((op[0] == '/' || op[0] == '%') && b == 0)
	{
		printf("Error\n");
		exit(100);
	}

	result = f(a, b);
	printf("%d\n", result);
	return (0);
}
