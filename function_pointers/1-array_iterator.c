#include "function_pointers.h"

/**
 * array_iterator - executes a function on each element of an int array
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @action: function pointer to apply to each element
 *
 * Return: void
 */
void array_iterator(int *array, size_t size, void (*action)(int))
{
	size_t i;

	if (array == NULL || action == NULL)
		return;

	for (i = 0; i < size; i++)
		action(array[i]);
}
