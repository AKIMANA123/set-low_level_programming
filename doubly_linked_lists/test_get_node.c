#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
dlistint_t *head = NULL;
dlistint_t *node;
int i;

/* Create a list: 10, 20, 30, 40, 50 */
for (i = 10; i <= 50; i += 10)
add_dnodeint_end(&head, i);

/* Test valid indices */
printf("Valid indices:\n");
for (i = 0; i < 5; i++)
{
node = get_dnodeint_at_index(head, i);
if (node != NULL)
printf("Index %d: %d\n", i, node->n);
}

/* Test invalid indices */
printf("\nInvalid indices:\n");
node = get_dnodeint_at_index(head, 10);
printf("Index 10 (out of range): %s\n", node == NULL ? "NULL" : "Found");

node = get_dnodeint_at_index(NULL, 0);
printf("Empty list, index 0: %s\n", node == NULL ? "NULL" : "Found");

/* Clean up */
free_dlistint(head);
return (0);
}
