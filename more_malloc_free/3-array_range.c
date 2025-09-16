#include "main.h"
#include <stdlib.h>

/**
 * array_range - creates an array of ints from min to max inclusive
 * @min: starting value
 * @max: ending value
 *
 * Return: pointer to new array, or NULL on failure / if min > max
 */
int *array_range(int min, int max)
{
	int *arr;
	int len, i;

	if (min > max)
		return (NULL);

	len = (max - min) + 1;

	arr = malloc(sizeof(int) * len);
	if (arr == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		arr[i] = min + i;

	return (arr);
}
