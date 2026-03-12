#include "main.h"
#include <stddef.h>

/**
 * _strstr - locates a substring
 * @haystack: string to search in
 * @needle: substring to search for
 *
 * Return: pointer to the beginning of the located substring,
 *         or NULL if the substring is not found
 */
char *_strstr(char *haystack, char *needle)
{
int i, j;

/* If needle is empty, return haystack */
if (needle[0] == '\0')
return (haystack);

for (i = 0; haystack[i] != '\0'; i++)
{
/* Check if needle matches starting at position i */
for (j = 0; needle[j] != '\0'; j++)
{
if (haystack[i + j] != needle[j])
break;
}
/* If we reached the end of needle, we found a match */
if (needle[j] == '\0')
return (&haystack[i]);
}

return (NULL);
}
