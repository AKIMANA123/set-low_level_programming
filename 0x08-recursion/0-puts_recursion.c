#include "main.h"

/**
 * _puts_recursion - prints a string, followed by a new line
 * @s: pointer to the string to print
 */
void _puts_recursion(char *s)
{
_putchar.c if (*s == '\0')
_putchar.c {
_putchar.c _putchar.c _putchar('\n');
_putchar.c _putchar.c return;
_putchar.c }
_putchar.c _putchar(*s);
_putchar.c _puts_recursion(s + 1);
}
