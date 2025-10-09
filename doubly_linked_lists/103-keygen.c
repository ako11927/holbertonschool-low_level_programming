#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static const char FALLBACK[] =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

/**
 * load_alphabet - try to extract the 64-char alphabet from ./crackme5
 * @alph: buffer where the alphabet is stored (65 bytes incl. NUL)
 * Return: 1 if found, 0 otherwise
 */
static int load_alphabet(char alph[65])
{
	FILE *fp;
	long sz;
	char *buf;
	size_t rd, i;
	const char *mark = "A-CHRDw87lNS0E9B2Tibgpn";

	alph[0] = '\0';
	fp = fopen("./crackme5", "rb");
	if (!fp)
		fp = fopen("crackme5", "rb");
	if (!fp)
		return (0);
	if (fseek(fp, 0L, SEEK_END) != 0)
	{
		fclose(fp);
		return (0);
	}
	sz = ftell(fp);
	if (sz <= 0 || sz > 20000000L)
	{
		fclose(fp);
		return (0);
	}
	rewind(fp);
	buf = (char *)malloc((size_t)sz);
	if (!buf)
	{
		fclose(fp);
		return (0);
	}
	rd = fread(buf, 1, (size_t)sz, fp);
	fclose(fp);
	for (i = 0; i + 64 <= rd; i++)
	{
		if (memcmp(buf + i, mark, 24) == 0)
		{
			memcpy(alph, buf + i, 64);
			alph[64] = '\0';
			free(buf);
			return (1);
		}
	}
	free(buf);
	return (0);
}

/**
 * main - prints a valid 6-char key for crackme5 (no trailing newline)
 * @ac: argument count
 * @av: argument vector
 * Return: 0 on success, 1 on misuse
 */
int main(int ac, char **av)
{
	const char *u;
	unsigned int len, i, sum, prod, mx, sq, r;
	char alph[65];
	char key[7];

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}
	if (!load_alphabet(alph))
		strcpy(alph, FALLBACK);

	u = av[1];
	len = (unsigned int)strlen(u);

	sum = 0;
	prod = 1;
	mx = 0;
	sq = 0;
	r = 0;

	key[0] = alph[(len ^ 59U) & 63U];

	for (i = 0; i < len; i++)
		sum += (unsigned int)u[i];
	key[1] = alph[(sum ^ 79U) & 63U];

	for (i = 0; i < len; i++)
		prod *= (unsigned int)u[i];
	key[2] = alph[(prod ^ 85U) & 63U];

	for (i = 0; i < len; i++)
		if ((unsigned int)u[i] > mx)
			mx = (unsigned int)u[i];
	srand(mx ^ 14U);
	key[3] = alph[rand() & 63U];

	for (i = 0; i < len; i++)
	{
		unsigned int c = (unsigned int)u[i];

		sq += c * c;
	}
	key[4] = alph[(sq ^ 239U) & 63U];

	for (i = 0; i < (unsigned int)u[0]; i++)
		r = (unsigned int)rand();
	key[5] = alph[(r ^ 229U) & 63U];

	key[6] = '\0';
	printf("%s", key);
	return (0);
}
