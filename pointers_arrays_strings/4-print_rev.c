#include "main.h"

/**
 * print_rev - Print a string in reverse followed by a newline.
 * @s: string to reverse-print
 *
 * Return: void
 */
void print_rev(char *s)
{
	int i = 0;

	while (s[i] != '\0')
		i++;

	while (i > 0)
	{
		i--;
		_putchar(s[i]);
	}
	_putchar('\n');
}
