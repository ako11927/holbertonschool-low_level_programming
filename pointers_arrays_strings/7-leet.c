#include "main.h"

/**
 * leet - Encodes a string into 1337.
 * @s: The string to encode.
 *
 * Description:
 * a/A -> 4, e/E -> 3, o/O -> 0, t/T -> 7, l/L -> 1
 * Constraints satisfied:
 * - Only one if in the code
 * - Only two loops
 * - No switch, no ternary
 *
 * Return: Pointer to @s.
 */
char *leet(char *s)
{
	int i, j;
	char from[] = "aAeEoOtTlL";
	char to[]   = "4433007711";

	for (i = 0; s[i] != '\0'; i++)
	{
		for (j = 0; from[j] != '\0'; j++)
		{
			if (s[i] == from[j])
			{
				s[i] = to[j];
				break;
			}
		}
	}
	return (s);
}
