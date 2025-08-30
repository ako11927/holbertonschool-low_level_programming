#include "main.h"

/**
 * print_most_numbers - prints 0..9 except 2 and 4, then newline
 */
void print_most_numbers(void)
{
	int d;

	for (d = '0'; d <= '9'; d++)
	{
		if (d == '2' || d == '4')
			continue;
		_putchar(d);
	}
	_putchar('\n');
}
