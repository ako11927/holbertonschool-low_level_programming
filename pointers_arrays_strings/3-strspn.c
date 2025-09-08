#include "main.h"

/**
 * _strspn - gets the length of a prefix substring
 * @s: string to scan
 * @accept: bytes to count from the start of @s
 *
 * Return: number of bytes in the initial segment of @s
 *         consisting only of bytes from @accept
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;
	int hit;
	char *a;

	while (*s)
	{
		hit = 0;
		for (a = accept; *a; a++)
		{
			if (*s == *a)
			{
				hit = 1;
				break;
			}
		}
		if (!hit)
			break;
		count++;
		s++;
	}
	return (count);
}
