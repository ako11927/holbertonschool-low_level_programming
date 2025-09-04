#include "main.h"

/**
 * _strncpy - Copies characters from one string to another
 * @dest: Buffer where the string is copied
 * @src: Source string
 * @n: Maximum number of characters to copy
 *
 * Description: Copies at most n characters from @src into @dest.
 * If @src is shorter than n, the remaining space in @dest
 * is filled with null bytes.
 *
 * Return: Pointer to @dest
 */

char *_strncpy(char *dest, char *src, int n)
{
	int i = 0;

	while (i < n && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}
