#include <stdio.h>
#include "main.h"

int main(void)
{
int a = 100;
int b = -50;
int c = 0;

printf("Before:\n");
printf("a = %d\n", a);
printf("b = %d\n", b);
printf("c = %d\n", c);

reset_to_98(&a);
reset_to_98(&b);
reset_to_98(&c);

printf("\nAfter:\n");
printf("a = %d\n", a);
printf("b = %d\n", b);
printf("c = %d\n", c);

return (0);
}
