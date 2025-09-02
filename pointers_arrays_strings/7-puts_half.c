#include "main.h"

/**
 * puts_half - Print the second half of a string followed by a newline.
 * @str: string to print
 *
 * Description: If the length is odd, print from (len + 1) / 2.
 * Return: void
 */
void puts_half(char *str)
{
	int len = 0, start, i;

	while (str[len] != '\0')
		len++;

	if (len % 2 == 0)
		start = len / 2;
	else
		start = (len + 1) / 2;

	for (i = start; i < len; i++)
		_putchar(str[i]);
	_putchar('\n');
}
