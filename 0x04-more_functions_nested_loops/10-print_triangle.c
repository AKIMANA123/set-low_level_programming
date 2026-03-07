#include "main.h"

/**
 * print_triangle - prints a triangle, followed by a new line
 * @size: size of the triangle
 */
void print_triangle(int size)
{
int i, j, spaces;

if (size > 0)
{
for (i = 1; i <= size; i++)
{
/* Print spaces */
for (spaces = size - i; spaces > 0; spaces--)
{
_putchar(' ');
}
/* Print hashes */
for (j = 0; j < i; j++)
{
_putchar('#');
}
_putchar('\n');
}
}
else
{
_putchar('\n');
}
}
