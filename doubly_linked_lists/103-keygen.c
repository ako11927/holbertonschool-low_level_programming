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
	int len, i, sum, prod, maxc, sumsqr, r;
	const char *alph =
		"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	u = av[1];
	len = (int)strlen(u);

	/* k0: from length */
	key[0] = alph[(len ^ 59) & 63];

	/* k1: sum of chars */
	sum = 0;
	for (i = 0; i < len; i++)
		sum += (int)u[i];
	key[1] = alph[(sum ^ 79) & 63];

	/* k2: product of chars (signed overflow intentional to match crackme) */
	prod = 1;
	for (i = 0; i < len; i++)
		prod *= (int)u[i];
	key[2] = alph[(prod ^ 85) & 63];

	/* k3: rng with (max char ^ 14) */
	maxc = 0;
	for (i = 0; i < len; i++)
		if ((int)u[i] > maxc)
			maxc = (int)u[i];
	srand(maxc ^ 14);
	key[3] = alph[rand() & 63];

	/* k4: sum of squares */
	sumsqr = 0;
	for (i = 0; i < len; i++)
	{
		int c = (int)u[i];

		sumsqr += c * c;
	}
	key[4] = alph[(sumsqr ^ 239) & 63];

	/* k5: advance rng u[0] times */
	for (i = 0, r = 0; i < (int)u[0]; i++)
		r = rand();
	key[5] = alph[(r ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
