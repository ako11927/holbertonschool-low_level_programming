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
	char alph[65] = {0};
	const char *fallback =
	"A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ";
	const char *marker = "A-CHRDw87lNS0E9B2Tibgpn";
	FILE *fp; long sz = 0; size_t rd = 0, i; char *buf = NULL;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	/* --- try to load the actual alphabet from the compiled crackme --- */
	fp = fopen("./crackme5", "rb");
	if (!fp)
		fp = fopen("crackme5", "rb");
	if (fp && !fseek(fp, 0L, SEEK_END))
	{
		sz = ftell(fp);
		if (sz > 0 && sz < 20000000)
		{
			rewind(fp);
			buf = malloc((size_t)sz);
			if (buf)
				rd = fread(buf, 1, (size_t)sz, fp);
		}
		fclose(fp);
	}
	if (buf && rd >= 64)
	{
		for (i = 0; i + 64 <= rd; i++)
		{
			if (memcmp(buf + i, marker, 24) == 0)
			{
				memcpy(alph, buf + i, 64);
				alph[64] = '\0';
				break;
			}
		}
	}
	free(buf);
	if (!alph[0])
		strcpy(alph, fallback);

	/* --- compute key (signed int arithmetic; overflows intentional) --- */
	{
		const char *u = av[1];
		int len = (int)strlen(u), i2, sum = 0, prod = 1, maxc = 0;
		int sumsqr = 0, r = 0; char key[7];

		key[0] = alph[(len ^ 59) & 63];

		for (i2 = 0; i2 < len; i2++)
			sum += (int)u[i2];
		key[1] = alph[(sum ^ 79) & 63];

		for (i2 = 0; i2 < len; i2++)
			prod *= (int)u[i2];
		key[2] = alph[(prod ^ 85) & 63];

		for (i2 = 0; i2 < len; i2++)
			if ((int)u[i2] > maxc)
				maxc = (int)u[i2];
		srand(maxc ^ 14);
		key[3] = alph[rand() & 63];

		for (i2 = 0; i2 < len; i2++)
		{
			int c = (int)u[i2];
			sumsqr += c * c;
		}
		key[4] = alph[(sumsqr ^ 239) & 63];

		for (i2 = 0, r = 0; i2 < (int)u[0]; i2++)
			r = rand();
		key[5] = alph[(r ^ 229) & 63];

		key[6] = '\0';
		printf("%s", key);
	}
	return (0);
}
