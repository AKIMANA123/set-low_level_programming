#include <stdlib.h>
#include "main.h"

/**
 * string_nconcat - concatenates two strings
 * @s1: first string
 * @s2: second string
 * @n: maximum number of bytes to take from s2
 *
 * Return: pointer to newly allocated space containing s1 + first n bytes of s2,
 * or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
char *concat;
unsigned int len1 = 0, len2 = 0, i, j;

/* Treat NULL as empty string */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

/* Calculate length of s1 */
while (s1[len1] != '\0')
len1++;

/* Calculate length of s2 (but limit to n) */
while (s2[len2] != '\0')
len2++;

/* If n is greater or equal to len2, use entire s2 */
if (n >= len2)
n = len2;

/* Allocate memory for concatenated string (+1 for null terminator) */
concat = malloc((len1 + n + 1) * sizeof(char));
if (concat == NULL)
return (NULL);

/* Copy s1 to concat */
for (i = 0; i < len1; i++)
concat[i] = s1[i];

/* Copy first n bytes of s2 to concat */
for (j = 0; j < n; j++)
concat[len1 + j] = s2[j];

/* Add null terminator */
concat[len1 + n] = '\0';

return (concat);
}
