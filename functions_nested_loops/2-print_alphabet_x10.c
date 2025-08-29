#include "main.h"

/**
 * print_alphabet_x10 - prints the alphabet 10 times
 */
void print_alphabet_x10(void)
{
	int row;
	char c;

	for (row = 0; row < 10; row++)
	{
		for (c = 'a'; c <= 'z'; c++)
			_putchar(c);
		_putchar('\n');
	}
}
