#include "main.h"

/**
 * print_numbers - prints 0..9 followed by newline
 */
void print_numbers(void)
{
	int d;

	for (d = '0'; d <= '9'; d++)
		_putchar(d);
	_putchar('\n');
}
