#include <stdlib.h>
#include "lists.h"

/**
 * create_node - creates a new node
 * @n: integer value to add to the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
static dlistint_t *create_node(int n)
{
dlistint_t *new_node;

new_node = malloc(sizeof(dlistint_t));
if (new_node == NULL)
return (NULL);

new_node->n = n;
new_node->prev = NULL;
new_node->next = NULL;

return (new_node);
}

/**
 * insert_at_beginning - inserts a node at the beginning of the list
 * @h: double pointer to the head of the list
 * @new_node: pointer to the new node
 *
 * Return: pointer to the new node
 */
static dlistint_t *insert_at_beginning(dlistint_t **h, dlistint_t *new_node)
{
new_node->next = *h;
if (*h != NULL)
(*h)->prev = new_node;
*h = new_node;
return (new_node);
}

/**
 * traverse_to_index - traverses to the node at given index
 * @head: pointer to the head of the list
 * @idx: index to traverse to
 *
 * Return: pointer to the node at index, or NULL if out of range
 */
static dlistint_t *traverse_to_index(dlistint_t *head, unsigned int idx)
{
unsigned int i;

for (i = 0; i < idx; i++)
{
if (head == NULL)
return (NULL);
head = head->next;
}
return (head);
}

/**
 * insert_before_node - inserts a new node before a given node
 * @node: pointer to the node before which to insert
 * @new_node: pointer to the new node
 *
 * Return: pointer to the new node
 */
static dlistint_t *insert_before_node(dlistint_t *node, dlistint_t *new_node)
{
new_node->prev = node->prev;
new_node->next = node;
node->prev = new_node;
if (new_node->prev != NULL)
new_node->prev->next = new_node;
return (new_node);
}

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

if (h == NULL)
return (NULL);

new_node = create_node(n);
if (new_node == NULL)
return (NULL);

if (idx == 0)
return (insert_at_beginning(h, new_node));

temp = traverse_to_index(*h, idx);
if (temp == NULL)
{
free(new_node);
return (NULL);
}

return (insert_before_node(temp, new_node));
}
