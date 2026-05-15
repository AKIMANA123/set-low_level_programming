#include "main.h"
#include <stdio.h>

int main(void)
{
/* Try to allocate an impossibly large amount of memory */
/* Use a large number that won't cause overflow warnings */
size_t large_size = (size_t)-1;  /* Maximum possible size_t value */
void *ptr = malloc_checked(large_size);

/* This line should never be reached if allocation fails */
printf("This should not print if allocation fails\n");
free(ptr);

return (0);
}
