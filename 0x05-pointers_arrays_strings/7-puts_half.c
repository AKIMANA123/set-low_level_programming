#include "main.h"

/**
 * puts_half - prints half of a string, followed by a new line
 * @str: pointer to the string
 */
void puts_half(char *str)
{
int length = 0;
int start, i;

/* Calculate the length of the string */
while (str[length] != '\0')
{
length++;
}

/* Determine the starting point for printing */
if (length % 2 == 0)
{
start = length / 2;
}
else
{
start = (length - 1) / 2 + 1;
}

/* Print from start to the end */
for (i = start; i < length; i++)
{
_putchar(str[i]);
}
_putchar('\n');
}
