#include "main.h"

/**
 * _strlen - compute length of a string
 * @s: string
 * Return: number of chars before '\0'
 */
int _strlen(char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}
