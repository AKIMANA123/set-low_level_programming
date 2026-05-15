#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint_end - adds a new node at the end of a listint_t list
 * @head: double pointer to the head of the list
 * @n: integer value to add to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
listint_t *new_node;
listint_t *temp;

if (head == NULL)
return (NULL);

/* Allocate memory for new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* Set the value and next pointer */
new_node->n = n;
new_node->next = NULL;

/* If list is empty, make new node the head */
if (*head == NULL)
{
*head = new_node;
return (new_node);
}

/* Traverse to the end of the list */
temp = *head;
while (temp->next != NULL)
temp = temp->next;

/* Add new node at the end */
temp->next = new_node;

return (new_node);
}
