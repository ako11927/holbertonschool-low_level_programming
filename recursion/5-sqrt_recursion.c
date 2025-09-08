#include "main.h"

/* helper to find natural sqrt recursively */
static int _sqrt_helper(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (_sqrt_helper(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number
 *
 * Return: natural sqrt of @n; -1 if none
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (_sqrt_helper(n, 0));
}
