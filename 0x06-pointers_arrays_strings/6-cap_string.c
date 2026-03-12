#include "main.h"

/**
 * is_separator - checks if a character is a word separator
 * @c: character to check
 *
 * Return: 1 if separator, 0 otherwise
 */
int is_separator(char c)
{
char separators[] = " \t\n,;.!?\"(){}";
int i;

for (i = 0; separators[i] != '\0'; i++)
{
if (c == separators[i])
return (1);
}
return (0);
}

/**
 * cap_string - capitalizes all words of a string
 * @str: pointer to the string
 *
 * Return: pointer to the resulting string
 */
char *cap_string(char *str)
{
int i = 0;

/* Capitalize first character if it's a letter */
if (str[i] >= 'a' && str[i] <= 'z')
{
str[i] = str[i] - 32;
}
i++;

/* Check the rest of the string */
while (str[i] != '\0')
{
/* If current character is a letter and previous is a separator */
if (is_separator(str[i - 1]) && (str[i] >= 'a' && str[i] <= 'z'))
{
str[i] = str[i] - 32;
}
i++;
}

return (str);
}
