#include "main.h"
#include <stdlib.h>

/**
 * str_concat - concatenates two strings into a newly allocated buffer
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 *
 * Return: pointer to new string, or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
	char *out;
	unsigned int len1 = 0, len2 = 0, i, j;

	if (s1 != NULL)
		while (s1[len1] != '\0')
			len1++;
	if (s2 != NULL)
		while (s2[len2] != '\0')
			len2++;

	out = malloc(sizeof(char) * (len1 + len2 + 1));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];
	for (j = 0; j < len2; j++)
		out[i + j] = s2[j];
	out[len1 + len2] = '\0';

	return (out);
}
