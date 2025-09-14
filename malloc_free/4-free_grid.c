#include "main.h"
#include <stdlib.h>

/**
 * free_grid - frees a 2D grid previously created by alloc_grid
 * @grid: pointer to the 2D array
 * @height: number of rows
 *
 * Return: void
 */
void free_grid(int **grid, int height)
{
	int r;

	if (grid == NULL || height <= 0)
		return;

	for (r = 0; r < height; r++)
		free(grid[r]);

	free(grid);
}
