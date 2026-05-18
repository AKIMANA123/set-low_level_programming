#include <stdlib.h>
#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index where the new node should be added (starts at 0)
 * @n: integer value to add to the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
listint_t *new_node;
listint_t *temp;
unsigned int i;

if (head == NULL)
return (NULL);

/* Create the new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->next = NULL;

/* Insert at the beginning (index 0) */
if (idx == 0)
{
new_node->next = *head;
*head = new_node;
return (new_node);
}

/* Traverse to the node before the insertion point */
temp = *head;
for (i = 0; i < idx - 1; i++)
{
if (temp == NULL || temp->next == NULL)
{
free(new_node);
return (NULL);
}
temp = temp->next;
}

/* Insert the new node */
new_node->next = temp->next;
temp->next = new_node;

return (new_node);
}
