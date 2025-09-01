#include "main.h"

/**
 * _atoi - convert string to integer
 * @s: string
 * Return: converted int, or 0 if no digits
 *
 * Handles any number of leading +/- signs: odd # of '-' makes result negative.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0;
	int result = 0;

	/* consume non-digits while tracking signs */
	while (s[i] != '\0' && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			sign = -sign;
		else if (s[i] == '+')
			; /* keep sign */
		i++;
	}

	/* accumulate digits */
	while (s[i] >= '0' && s[i] <= '9')
	{
		started = 1;
		result = result * 10 + (s[i] - '0');
		i++;
	}

	if (!started)
		return (0);

	return (sign * result);
}
