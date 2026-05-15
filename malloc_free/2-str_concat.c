#include <stdlib.h>
#include "main.h"

/**
 * str_concat - concatenates two strings
 * @s1: first string
 * @s2: second string
 *
 * Return: pointer to newly allocated space containing s1 + s2,
 * or NULL on failure
 */
char *str_concat(char *s1, char *s2)
{
char *concat;
unsigned int len1 = 0, len2 = 0, i, j;

/* Treat NULL as empty string */
if (s1 == NULL)
s1 = "";
if (s2 == NULL)
s2 = "";

/* Calculate lengths */
while (s1[len1] != '\0')
len1++;
while (s2[len2] != '\0')
len2++;

/* Allocate memory for concatenated string (+1 for null terminator) */
concat = malloc((len1 + len2 + 1) * sizeof(char));
if (concat == NULL)
return (NULL);

/* Copy s1 to concat */
for (i = 0; i < len1; i++)
concat[i] = s1[i];

/* Copy s2 to concat */
for (j = 0; j < len2; j++)
concat[len1 + j] = s2[j];

/* Add null terminator */
concat[len1 + len2] = '\0';

return (concat);
}
