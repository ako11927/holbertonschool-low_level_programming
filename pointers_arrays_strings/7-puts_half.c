#include "main.h"

/**
 * puts_half - print second half of a string followed by newline
 * @str: string
 *
 * If length is odd, start at (len + 1) / 2.
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	while (str[len] != '\0')
		len++;

	start = (len % 2 == 0) ? (len / 2) : ((len + 1) / 2);

	for (i = start; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
