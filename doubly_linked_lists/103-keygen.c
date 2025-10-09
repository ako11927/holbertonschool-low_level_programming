#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Exactly 64 chars (+1 for '\0'); must match crackme5 */
static const char ALPH[65] =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

int main(int ac, char **av)
{
	int len, i, sum = 0, prod = 1, mx, sq = 0, r;
	char *u, key[7];

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	/* sanity: refuse to run with a bad alphabet */
	if ((int)(sizeof(ALPH) - 1) != 64)
		return (1);

	u = av[1];
	len = (int)strlen(u);

	/* 1 */
	key[0] = ALPH[(len ^ 59) & 63];

	/* 2 */
	for (i = 0; i < len; i++)
		sum += (int)u[i];
	key[1] = ALPH[(sum ^ 79) & 63];

	/* 3 (signed overflow on purpose) */
	for (i = 0; i < len; i++)
		prod *= (int)u[i];
	key[2] = ALPH[(prod ^ 85) & 63];

	/* 4 */
	mx = (int)u[0];
	for (i = 0; i < len; i++)
		if ((int)u[i] > mx)
			mx = (int)u[i];
	srand(mx ^ 14);
	key[3] = ALPH[rand() & 63];

	/* 5 */
	for (i = 0; i < len; i++)
	{
		int c = (int)u[i];
		sq += c * c;
	}
	key[4] = ALPH[(sq ^ 239) & 63];

	/* 6 */
	r = 0;
	for (i = 0; i < (int)u[0]; i++)
		r = rand();
	key[5] = ALPH[(r ^ 229) & 63];

	key[6] = '\0';
	printf("%s", key); /* no newline */
	return (0);
}
