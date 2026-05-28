#include <stdlib.h>
#include "lists.h"

/**
 * insert_dnodeint_at_index - inserts a new node at a given position
 * @h: double pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: integer value to add to the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
dlistint_t *new_node;
dlistint_t *temp;
unsigned int i;

if (h == NULL)
return (NULL);

/* Create new node */
new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;

/* Insert at beginning */
if (idx == 0)
{
new_node->prev = NULL;
new_node->next = *h;
if (*h != NULL)
(*h)->prev = new_node;
*h = new_node;
return (new_node);
}

/* Traverse to the node at the insertion point */
temp = *h;
for (i = 0; i < idx; i++)
{
if (temp == NULL)
{
free(new_node);
return (NULL);
}
temp = temp->next;
}

/* If we reached NULL, index is beyond list length */
if (temp == NULL)
{
free(new_node);
return (NULL);
}

/* Insert before temp */
new_node->prev = temp->prev;
new_node->next = temp;
temp->prev = new_node;
if (new_node->prev != NULL)
new_node->prev->next = new_node;

return (new_node);
}
