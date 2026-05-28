#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
dlistint_t *head = NULL;
dlistint_t *node1, *node2, *node3;
size_t n;

/* Create nodes manually */
node1 = malloc(sizeof(dlistint_t));
node2 = malloc(sizeof(dlistint_t));
node3 = malloc(sizeof(dlistint_t));

if (!node1 || !node2 || !node3)
return (1);

node1->n = 10;
node1->prev = NULL;
node1->next = node2;

node2->n = 20;
node2->prev = node1;
node2->next = node3;

node3->n = 30;
node3->prev = node2;
node3->next = NULL;

head = node1;

/* Test with 3 nodes */
n = dlistint_len(head);
printf("List with 3 nodes: %lu elements\n", n);

/* Test with empty list */
n = dlistint_len(NULL);
printf("Empty list: %lu elements\n", n);

/* Clean up */
free(node1);
free(node2);
free(node3);

return (0);
}
