#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sums of the two diagonals
 *                  of a square matrix of integers
 * @a: pointer to the first element of the matrix (as int *)
 * @size: dimension of the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	long sum1 = 0;
	long sum2 = 0;

	for (i = 0; i < size; i++)
	{
		sum1 += a[i * size + i];
		sum2 += a[i * size + (size - 1 - i)];
	}

	printf("%ld, %ld\n", sum1, sum2);
}
