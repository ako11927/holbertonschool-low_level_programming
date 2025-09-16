#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates s1 with first n bytes of s2
 * @s1: first string (treated as "" if NULL)
 * @s2: second string (treated as "" if NULL)
 * @n:  number of bytes of s2 to append
 *
 * Return: pointer to newly allocated string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	unsigned int len1 = 0, len2 = 0, i, j;
	char *out;

	if (s1 != NULL)
		while (s1[len1] != '\0')
			len1++;

	if (s2 != NULL)
		while (s2[len2] != '\0')
			len2++;

	if (n >= len2)
		n = len2;

	out = malloc(sizeof(char) * (len1 + n + 1));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];

	for (j = 0; j < n; j++)
		out[i + j] = s2[j];

	out[len1 + n] = '\0';
	return (out);
}
