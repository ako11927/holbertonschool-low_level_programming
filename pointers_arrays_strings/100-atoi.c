#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to be converted
 *
 * Return: the integer value of the string, or 0 if no numbers found
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;

	/* skip non-digit characters and count signs */
	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign *= -1;
		i++;
	}

	/* process digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		result = result * 10 + (s[i] - '0');
		i++;
	}

	return (result * sign);
}
