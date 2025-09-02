#include "main.h"

/**
 * _strcpy - Copy the string pointed to by src to dest (including '\0').
 * @dest: destination buffer
 * @src: source string
 *
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	do {
		dest[i] = src[i];
		i++;
	} while (src[i - 1] != '\0');

	return (dest);
}
