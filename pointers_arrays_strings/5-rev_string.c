#include "main.h"

/**
 * rev_string - reverse a string in place
 * @s: string to reverse
 */
void rev_string(char *s)
{
	int i = 0, j = 0;
	char tmp;

	while (s[j] != '\0')
		j++;

	j--; /* last valid index */
	while (i < j)
	{
		tmp = s[i];
		s[i] = s[j];
		s[j] = tmp;
		i++;
		j--;
	}
}
