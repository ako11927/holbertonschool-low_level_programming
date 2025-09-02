#include "main.h"

/**
 * swap_int - Swap the values of two integers.
 * @a: pointer to first integer
 * @b: pointer to second integer
 *
 * Return: void
 */
void swap_int(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
