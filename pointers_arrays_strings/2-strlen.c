#include "main.h"

/**
 * _strlen - Return the length of a string.
 * @s: string to measure
 *
 * Return: number of characters before the terminating null byte
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
