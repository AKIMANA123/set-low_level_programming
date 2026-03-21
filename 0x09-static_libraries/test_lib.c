#include "main.h"

int main(void)
{
    /* Test _puts */
    _puts("Testing static library:");
    
    /* Test _putchar */
    _putchar('A');
    _putchar('B');
    _putchar('C');
    _putchar('\n');
    
    /* Test _isupper */
    _putchar('A');
    _putchar(':');
    _putchar(_isupper('A') + '0');
    _putchar('\n');
    
    /* Test _islower */
    _putchar('a');
    _putchar(':');
    _putchar(_islower('a') + '0');
    _putchar('\n');
    
    /* Test _abs */
    _puts("Absolute values:");
    /* Need to print numbers - use printf for this test */
    /* But we're just testing compilation */
    
    return (0);
}
