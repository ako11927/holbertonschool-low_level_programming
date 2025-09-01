#include "main.h"

/**
 * _strcpy - copy string src (including '\0') to dest
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
char *_strcpy(char *dest, char *src)
{
	int i = 0;

	do {
		dest[i] = src[i];
	} while (src[i++] != '\0');

	return (dest);
}

