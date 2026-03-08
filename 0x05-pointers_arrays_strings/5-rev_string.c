#include "main.h"

/**
 * rev_string - reverses a string
 * @s: pointer to the string to reverse
 */
void rev_string(char *s)
{
int length = 0;
int i, j;
char temp;

/* Calculate the length of the string */
while (s[length] != '\0')
{
length++;
}

/* Swap characters from both ends */
for (i = 0, j = length - 1; i < j; i++, j--)
{
temp = s[i];
s[i] = s[j];
s[j] = temp;
}
}
