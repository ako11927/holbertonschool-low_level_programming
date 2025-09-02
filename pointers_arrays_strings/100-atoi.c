#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description:
 * Build the value as a NEGATIVE number to avoid overflow on INT_MIN.
 * If the final sign is positive, negate at the end (unless result is INT_MIN,
 * which would overflow if negated; in that case, just return INT_MIN).
 *
 * Return: converted int, or 0 if no digits found
 */
int _atoi(char *s)
{
	int i = 0;
	int neg = 0;         /* count '-' signs */
	int found = 0;       /* saw at least one digit */
	int result = 0;      /* keep as negative during accumulation */

	/* skip non-digits, track signs */
	while (s[i] && (s[i] < '0' || s[i] > '9'))
	{
		if (s[i] == '-')
			neg++;
		i++;
	}

	/* accumulate as negative: result = result*10 - digit */
	while (s[i] >= '0' && s[i] <= '9')
	{
		found = 1;
		result = result * 10 - (s[i] - '0');
		i++;
	}

	if (!found)
		return (0);

	/* if odd number of '-', number stays negative: return result */
	if (neg % 2 == 1)
		return (result);

	/* positive sign: safely negate unless result is INT_MIN */
	if (result == (-2147483647 - 1))
		return (-2147483647 - 1);

	return (-result);
}
