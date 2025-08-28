#include <stdio.h>
/**
 * main - Prints all single digit numbers of base 10 starting from 0
 *        using putchar and no char variables
 * Return: Always 0 (Success)
 */
int main(void)
{
	int i;

	for (i = 0; i < 10; i++)
		putchar(i + '0');
	putchar('\n');
	return (0);
}
