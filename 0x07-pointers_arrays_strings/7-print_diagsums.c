#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (treated as 1D array)
 * @size: size of the matrix (number of rows/columns)
 */
void print_diagsums(int *a, int size)
{
int i;
long int sum1 = 0;  /* Sum of main diagonal (top-left to bottom-right) */
long int sum2 = 0;  /* Sum of secondary diagonal (top-right to bottom-left) */

for (i = 0; i < size; i++)
{
/* Main diagonal: elements at positions (i, i) */
sum1 += a[i * size + i];

/* Secondary diagonal: elements at positions (i, size-1-i) */
sum2 += a[i * size + (size - 1 - i)];
}

printf("%ld, %ld\n", sum1, sum2);
}
