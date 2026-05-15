#include <stdlib.h>
#include "lists.h"

/**
 * add_nodeint - adds a new node at the beginning of a listint_t list
 * @head: double pointer to the head of the list
 * @n: integer value to add to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
listint_t *new_node;

if (head == NULL)
return (NULL);

/* Allocate memory for new node */
new_node = malloc(sizeof(listint_t));
if (new_node == NULL)
return (NULL);

/* Set the value */
new_node->n = n;

/* Point new node to current head */
new_node->next = *head;

/* Update head to point to new node */
*head = new_node;

return (new_node);
}
