#include "main.h"

/**
 * _strncpy - Copies a string.
 * @dest: Destination buffer.
 * @src: Source string.
 * @n: Maximum number of bytes to copy.
 *
 * Description: Works like the standard strncpy:
 * - Copies up to n bytes from src to dest.
 * - If src is shorter than n, the remainder of dest is padded with '\0'.
 *
 * Return: Pointer to @dest.
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
