#include "main.h"

/* helper: checks divisibility starting from i */
static int _prime_helper(int n, int i)
{
	if (i * i > n)
		return (1);
	if (n % i == 0)
		return (0);
	return (_prime_helper(n, i + 2));
}

/**
 * is_prime_number - checks if an integer is a prime number
 * @n: number to check
 *
 * Return: 1 if prime, 0 otherwise
 */
int is_prime_number(int n)
{
	if (n <= 1)
		return (0);
	if (n == 2)
		return (1);
	if (n % 2 == 0)
		return (0);
	return (_prime_helper(n, 3));
}
