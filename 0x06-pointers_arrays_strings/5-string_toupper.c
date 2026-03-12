#include "main.h"

/**
 * string_toupper - changes all lowercase letters of a string to uppercase
 * @str: pointer to the string
 *
 * Return: pointer to the resulting string
 */
char *string_toupper(char *str)
{
int i = 0;

while (str[i] != '\0')
{
/* Check if character is lowercase (a-z) */
if (str[i] >= 'a' && str[i] <= 'z')
{
/* Convert to uppercase by subtracting 32 */
str[i] = str[i] - 32;
}
i++;
}

return (str);
}
