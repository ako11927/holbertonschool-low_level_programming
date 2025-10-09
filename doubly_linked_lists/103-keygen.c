#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - generates a valid key for crackme5
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, 1 on misuse
 */
int main(int ac, char **av)
{
	char key[7];
	const char *u;
	unsigned int len, i, sum, prod, maxc, sumsqr, r;
	const char *alph =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	u = av[1];
	len = (unsigned int)strlen(u);

	/* k0: length */
	key[0] = alph[(len ^ 59U) & 63U];

	/* k1: sum of chars */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += (unsigned int)u[i];
	key[1] = alph[(sum ^ 79U) & 63U];

	/* k2: product of chars (overflow intentional) */
	prod = 1;
	for (i = 0; i < len; i++)
		prod *= (unsigned int)u[i];
	key[2] = alph[(prod ^ 85U) & 63U];

	/* k3: rng with (max char ^ 14) */
	maxc = 0;
	for (i = 0; i < len; i++)
		if ((unsigned int)u[i] > maxc)
			maxc = (unsigned int)u[i];
	srand(maxc ^ 14U);
	key[3] = alph[rand() & 63U];

	/* k4: sum of squares */
	sumsqr = 0;
	for (i = 0; i < len; i++)
	{
		unsigned int c = (unsigned int)u[i];

		sumsqr += c * c;
	}
	key[4] = alph[(sumsqr ^ 239U) & 63U];

	/* k5: advance rng username[0] times */
	for (i = 0, r = 0; i < (unsigned int)u[0]; i++)
		r = (unsigned int)rand();
	key[5] = alph[(r ^ 229U) & 63U];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
