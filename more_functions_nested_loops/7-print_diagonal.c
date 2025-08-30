#include "main.h"

/**
 * print_diagonal - draws a diagonal line
 * @n: number of backslashes to print
 */
void print_diagonal(int n)
{
	int i, s;

	if (n <= 0)
	{
		_putchar('\n');
		return;
	}
	for (i = 0; i < n; i++)
	{
		for (s = 0; s < i; s++)
			_putchar(' ');
		_putchar('\\');
		_putchar('\n');
	}
}
