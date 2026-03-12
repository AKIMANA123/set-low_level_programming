#include <stdio.h>
#include "main.h"

int main(void)
{
char dest1[50] = "Hello";
char src1[] = " World";

char dest2[50] = "";
char src2[] = "Hello";

char dest3[50] = "ABC";
char src3[] = "";

char dest4[50] = "First ";
char src4[] = "Second ";
char src5[] = "Third";

printf("Test 1: '%s' + '%s' = ", dest1, src1);
_strcat(dest1, src1);
printf("'%s'\n", dest1);

printf("Test 2: '%s' + '%s' = ", dest2, src2);
_strcat(dest2, src2);
printf("'%s'\n", dest2);

printf("Test 3: '%s' + '%s' = ", dest3, src3);
_strcat(dest3, src3);
printf("'%s'\n", dest3);

printf("Test 4: Multiple concatenations:\n");
printf("  Start: '%s'\n", dest4);
_strcat(dest4, src4);
printf("  After first: '%s'\n", dest4);
_strcat(dest4, src5);
printf("  After second: '%s'\n", dest4);

return (0);
}
