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
	/* ---- 1) load alphabet from ./crackme5 (robust to checker variants) ---- */
	char alph[65];
	const char *marker = "A-CHRDw87lNS0E9B2Tibgpn";
	char *buf = NULL;
	long fsz = 0;
	size_t rd = 0, i;
	FILE *fp;

	if (ac != 2)
	{
		fprintf(stderr, "Usage: %s username\n", av[0]);
		return (1);
	}

	fp = fopen("crackme5", "rb");
	if (!fp)
		fp = fopen("./crackme5", "rb");
	if (fp)
	{
		if (fseek(fp, 0L, SEEK_END) == 0)
		{
			fsz = ftell(fp);
			if (fsz > 0 && fsz < 20 * 1024 * 1024)
			{
				rewind(fp);
				buf = malloc((size_t)fsz);
				if (buf)
				{
					rd = fread(buf, 1, (size_t)fsz, fp);
				}
			}
		}
		fclose(fp);
	}
	alph[0] = '\0';
	if (buf && rd)
	{
		for (i = 0; i + 64 <= rd; i++)
		{
			if (memcmp(buf + i, marker, strlen(marker)) == 0)
			{
				memcpy(alph, buf + i, 64);
				alph[64] = '\0';
				break;
			}
		}
	}
	free(buf);

	/* fallback alphabet if not found (common checker variant) */
	if (alph[0] == '\0')
		strcpy(alph,
		       "A-CHRDw87lNS0E9B2TibgpnMVys5XzvtOGJcYLU+4mjW6fxqZ");

	/* ---- 2) standard crackme5 math (signed ints, overflow intentional) ---- */
	{
		char key[7];
		const char *u = av[1];
		int len = (int)strlen(u);
		int sum, prod, maxc, sumsqr, r;
		int j;

		/* k0 */
		key[0] = alph[(len ^ 59) & 63];

		/* k1 */
		sum = 0;
		for (j = 0; j < len; j++)
			sum += (int)u[j];
		key[1] = alph[(sum ^ 79) & 63];

		/* k2 */
		prod = 1;
		for (j = 0; j < len; j++)
			prod *= (int)u[j];
		key[2] = alph[(prod ^ 85) & 63];

		/* k3 */
		maxc = 0;
		for (j = 0; j < len; j++)
			if ((int)u[j] > maxc)
				maxc = (int)u[j];
		srand(maxc ^ 14);
		key[3] = alph[rand() & 63];

		/* k4 */
		sumsqr = 0;
		for (j = 0; j < len; j++)
		{
			int c = (int)u[j];

			sumsqr += c * c;
		}
		key[4] = alph[(sumsqr ^ 239) & 63];

		/* k5 */
		for (j = 0, r = 0; j < (int)u[0]; j++)
			r = rand();
		key[5] = alph[(r ^ 229) & 63];

		key[6] = '\0';
		printf("%s", key);
	}
	return (0);
}
