#include "main.h"

/**
 * main - prints "_putchar" and a newline
 * Return: 0
 */
int main(void)
{
	const char *s = "_putchar";
	int i = 0;

	while (s[i])
	{
		_putchar(s[i]);
		i++;
	}
	_putchar('\n');
	return (0);
}
