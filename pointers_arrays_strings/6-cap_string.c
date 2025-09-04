#include "main.h"

/**
 * is_sep - Checks if a character is a word separator.
 * @c: Character to check.
 *
 * Return: 1 if separator, 0 otherwise.
 */
static int is_sep(char c)
{
	int i;
	char seps[] = " \t\n,;.!?\"(){}";

	for (i = 0; seps[i] != '\0'; i++)
	{
		if (c == seps[i])
			return (1);
	}
	return (0);
}

/**
 * cap_string - Capitalizes all words of a string.
 * @s: The string.
 *
 * Return: Pointer to @s.
 */
char *cap_string(char *s)
{
	int i = 0;
	int cap_next = 1;

	while (s[i] != '\0')
	{
		if (cap_next && s[i] >= 'a' && s[i] <= 'z')
			s[i] -= ('a' - 'A');

		cap_next = is_sep(s[i]) ? 1 : 0;
		i++;
	}
	return (s);
}
