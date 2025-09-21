#include "function_pointers.h"

/**
 * print_name - calls a function to print a name
 * @name: string to pass to the printing function
 * @f: pointer to a function that takes a char* and returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (name == NULL || f == NULL)
		return;

	f(name);
}
