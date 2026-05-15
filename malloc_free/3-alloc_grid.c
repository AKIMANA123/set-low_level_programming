#include <stdlib.h>
#include "main.h"

/**
 * alloc_grid - returns a pointer to a 2 dimensional array of integers
 * @width: width of the grid
 * @height: height of the grid
 *
 * Return: pointer to 2D array, or NULL on failure
 */
int **alloc_grid(int width, int height)
{
int **grid;
int i, j;

if (width <= 0 || height <= 0)
return (NULL);

/* Allocate memory for rows (height) */
grid = malloc(height * sizeof(int *));
if (grid == NULL)
return (NULL);

/* Allocate memory for columns (width) in each row */
for (i = 0; i < height; i++)
{
grid[i] = malloc(width * sizeof(int));
if (grid[i] == NULL)
{
/* Free previously allocated memory on failure */
for (j = 0; j < i; j++)
free(grid[j]);
free(grid);
return (NULL);
}
}

/* Initialize all elements to 0 */
for (i = 0; i < height; i++)
{
for (j = 0; j < width; j++)
grid[i][j] = 0;
}

return (grid);
}
