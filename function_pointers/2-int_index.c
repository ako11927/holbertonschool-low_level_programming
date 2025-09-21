#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparison function
 * @array: array of integers
 * @size: number of elements in the array
 * @cmp: pointer to function to compare values; returns non-zero on match
 *
 * Return: index of first element where cmp != 0, or -1 on failure/no match
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]))
			return (i);
	}

	return (-1);
}
