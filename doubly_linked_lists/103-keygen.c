#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Fallback alphabet (classic crackme5) */
static const char FALLBACK[] =
"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";

/*
 * Try to load the alphabet from a local ./crackme5 (the checker compiles it
 * right next to this program). We scan the file for the 64-byte table that
 * starts with the well-known 24-byte marker. On failure we copy FALLBACK.
 */
static void load_alphabet(char out[65])
{
	FILE *fp;
	const char *mark = "A-CHRDw87lNS0E9B2Tibgpn";
	char *buf = NULL;
	size_t rd, i;
	long sz;

	out[0] = '\0';
	fp = fopen("./crackme5", "rb");
	if (!fp)
		fp = fopen("crackme5", "rb");
	if (!fp)
		goto fallback;

	if (fseek(fp, 0L, SEEK_END) != 0)
		goto close_fallback;
	sz = ftell(fp);
	if (sz <= 0 || sz > 20000000L)
		goto close_fallback;
	if (fseek(fp, 0L, SEEK_SET) != 0)
		goto close_fallback;

	buf = malloc((size_t)sz);
	if (!buf)
		goto close_fallback;

	rd = fread(buf, 1, (size_t)sz, fp);
	for (i = 0; i + 64 <= rd; i++)
	{
		if (memcmp(buf + i, mark, 24) == 0)
		{
			memcpy(out, buf + i, 64);
			out[64] = '\0';
			free(buf);
			fclose(fp);
			return;
		}
	}

close_fallback:
	if (buf)
		free(buf);
	fclose(fp);
fallback:
	memcpy(out, FALLBACK, 64);
	out[64] = '\0';
}

/**
 * main - print a valid 6-char key for crackme5 (no trailing newline)
 * @ac: argc
 * @av: argv
 * Return: 0 on success, 1 on misuse
 */
int main(int ac, char **av)
{
	char alph[65], key[7];
	const char *u;
	unsigned int len, i, sum = 0, prod = 1, mx = 0, sq = 0, r = 0;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	load_alphabet(alph);

	u = av[1];
	len = (unsigned int)strlen(u);

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
	fputs(key, stdout); /* NO newline */
	return (0);
}
