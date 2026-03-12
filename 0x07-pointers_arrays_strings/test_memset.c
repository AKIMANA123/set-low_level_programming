#include <stdio.h>
#include "main.h"

void print_buffer(char *buffer, int size)
{
int i;
for (i = 0; i < size; i++)
{
if (i % 10 == 0 && i != 0)
printf("\n");
printf("0x%02x ", (unsigned char)buffer[i]);
}
printf("\n");
}

int main(void)
{
char buffer1[20];
char buffer2[30];
char buffer3[15];
int i;

/* Initialize buffers with known values */
for (i = 0; i < 20; i++)
buffer1[i] = 0xFF;

for (i = 0; i < 30; i++)
buffer2[i] = 0xAA;

for (i = 0; i < 15; i++)
buffer3[i] = 0x55;

printf("Test 1: Fill first 10 bytes of buffer1 with 0x42\n");
printf("Before:\n");
print_buffer(buffer1, 20);
_memset(buffer1, 0x42, 10);
printf("After:\n");
print_buffer(buffer1, 20);
printf("\n");

printf("Test 2: Fill first 5 bytes of buffer2 with 0x00\n");
printf("Before:\n");
print_buffer(buffer2, 15);
_memset(buffer2, 0x00, 5);
printf("After:\n");
print_buffer(buffer2, 15);
printf("\n");

printf("Test 3: Fill entire buffer3 with 0x99\n");
printf("Before:\n");
print_buffer(buffer3, 15);
_memset(buffer3, 0x99, 15);
printf("After:\n");
print_buffer(buffer3, 15);
printf("\n");

printf("Test 4: Fill 0 bytes (should do nothing)\n");
printf("Before (first 5 bytes): ");
for (i = 0; i < 5; i++)
printf("0x%02x ", (unsigned char)buffer1[i]);
printf("\n");
_memset(buffer1, 0x00, 0);
printf("After (first 5 bytes):  ");
for (i = 0; i < 5; i++)
printf("0x%02x ", (unsigned char)buffer1[i]);
printf("\n");

return (0);
}
