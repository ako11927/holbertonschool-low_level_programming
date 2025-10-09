#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Alphabet used by crackme5 */
static const char ALPH[] =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

int main(int ac, char **av)
{
	/* variables kept unsigned to match the original overflow behavior */
	const char *u;
	unsigned int len, i, sum = 0, prod = 1, mx = 0, sq = 0, r = 0;
	char key[7];

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	u = av[1];
	len = (unsigned int)strlen(u);

	key[0] = ALPH[(len ^ 59U) & 63U];

	for (i = 0; i < len; i++)
		sum += (unsigned int)u[i];
	key[1] = ALPH[(sum ^ 79U) & 63U];

	for (i = 0; i < len; i++)
		prod *= (unsigned int)u[i];
	key[2] = ALPH[(prod ^ 85U) & 63U];

	for (i = 0; i < len; i++)
		if ((unsigned int)u[i] > mx)
			mx = (unsigned int)u[i];
	srand(mx ^ 14U);
	key[3] = ALPH[rand() & 63U];

	for (i = 0; i < len; i++)
	{
		unsigned int c = (unsigned int)u[i];

		sq += c * c;
	}
	key[4] = ALPH[(sq ^ 239U) & 63U];

	for (i = 0, r = 0; i < (unsigned int)u[0]; i++)
		r = (unsigned int)rand();
	key[5] = ALPH[(r ^ 229U) & 63U];

	/* print 6 chars, NO newline */
	fwrite(key, 1, 6, stdout);
	return (0);
}
