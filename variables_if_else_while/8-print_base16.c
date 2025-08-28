#include <stdio.h>
/**
 * main - Prints all the numbers of base 16 in lowercase
 * Return: Always 0 (Success)
 */
int main(void)
{
	int d;
	char a;
	for (d = 0; d < 10; d++)
		putchar(d + '0');
	for (a = 'a'; a <= 'f'; a++)
		putchar(a);
	putchar('\n');
	return (0);
}
