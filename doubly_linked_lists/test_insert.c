#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

int main(void)
{
dlistint_t *head = NULL;
dlistint_t *node;

/* Test insert at index 0 */
node = insert_dnodeint_at_index(&head, 0, 98);
if (node != NULL)
printf("Inserted %d at index 0\n", node->n);
else
printf("Failed to insert\n");

return (0);
}
