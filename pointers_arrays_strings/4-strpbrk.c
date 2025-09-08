#include "main.h"

/**
 * _strpbrk - searches a string for any of a set of bytes
 * @s: string to scan
 * @accept: set of bytes to match
 *
 * Return: pointer to first matching byte in @s, or NULL if none
 */
char *_strpbrk(char *s, char *accept)
{
	char *a;

	while (*s)
	{
		for (a = accept; *a; a++)
		{
			if (*s == *a)
				return (s);
		}
		s++;
	}
	return (0);
}
