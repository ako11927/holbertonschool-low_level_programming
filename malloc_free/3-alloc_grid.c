#include "main.h"
#include <stdlib.h>

/**
 * alloc_grid - returns a pointer to a 2D array of integers
 * @width: number of columns
 * @height: number of rows
 *
 * Return: pointer to 2D array initialized to 0, or NULL on failure/invalid
 */
int **alloc_grid(int width, int height)
{
	int **grid;
	int r, c;

	if (width <= 0 || height <= 0)
		return (NULL);

	grid = malloc(sizeof(int *) * height);
	if (grid == NULL)
		return (NULL);

	for (r = 0; r < height; r++)
	{
		grid[r] = malloc(sizeof(int) * width);
		if (grid[r] == NULL)
		{
			while (r > 0)
			{
				r--;
				free(grid[r]);
			}
			free(grid);
			return (NULL);
		}

		for (c = 0; c < width; c++)
			grid[r][c] = 0;
	}

	return (grid);
}
