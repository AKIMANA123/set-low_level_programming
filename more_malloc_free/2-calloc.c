#include <stdlib.h>
#include "main.h"

/**
 * _calloc - allocates memory for an array of nmemb elements of size bytes each
 * and sets the memory to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated memory, or NULL if nmemb or size is 0,
 * or if malloc fails
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
void *ptr;
unsigned int total_size;
unsigned int i;
char *char_ptr;

if (nmemb == 0 || size == 0)
return (NULL);

total_size = nmemb * size;

ptr = malloc(total_size);
if (ptr == NULL)
return (NULL);

/* Set memory to zero */
char_ptr = (char *)ptr;
for (i = 0; i < total_size; i++)
char_ptr[i] = 0;

return (ptr);
}
