#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
listint_t *head = NULL;
listint_t *node;
int i;

/* Create a list: 10, 20, 30, 40, 50 */
for (i = 10; i <= 50; i += 10)
add_nodeint_end(&head, i);

/* Test valid indices */
for (i = 0; i < 5; i++)
{
node = get_nodeint_at_index(head, i);
if (node != NULL)
printf("Index %d: %d\n", i, node->n);
}

/* Test invalid indices */
node = get_nodeint_at_index(head, 10);
printf("Index 10 (out of range): %s\n", node == NULL ? "NULL" : "Found");

node = get_nodeint_at_index(NULL, 0);
printf("Empty list, index 0: %s\n", node == NULL ? "NULL" : "Found");

free_listint2(&head);
return (0);
}
