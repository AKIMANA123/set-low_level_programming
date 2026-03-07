#include <stdio.h>
#include "main.h"

int main(void)
{
printf("Z: %d\n", _isupper('Z'));
printf("z: %d\n", _isupper('z'));
printf("M: %d\n", _isupper('M'));
printf("m: %d\n", _isupper('m'));
printf("5: %d\n", _isupper('5'));
printf("@: %d\n", _isupper('@'));
printf("[ (ASCII 91): %d\n", _isupper('['));
return (0);
}
