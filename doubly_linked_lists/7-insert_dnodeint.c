#include <stdlib.h>
#include "lists.h"

/**
 * create_new_node - creates a new node
 * @n: integer value for the node
 *
 * Return: pointer to new node, or NULL on failure
 */
static dlistint_t *create_new_node(int n)
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
 * insert_at_beginning - inserts node at index 0
 * @head: double pointer to head of list
 * @new_node: node to insert
 *
 * Return: pointer to new node
 */
static dlistint_t *insert_at_beginning(dlistint_t **head, dlistint_t *new_node)
{
new_node->next = *head;
if (*head != NULL)
(*head)->prev = new_node;
*head = new_node;

return (new_node);
}

/**
 * traverse_to_node - traverses to node at given index
 * @head: pointer to head of list
 * @idx: index to traverse to
 *
 * Return: pointer to node at index, or NULL if out of range
 */
static dlistint_t *traverse_to_node(dlistint_t *head, unsigned int idx)
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
 * insert_before_node - inserts new node before given node
 * @node: node to insert before
 * @new_node: node to insert
 *
 * Return: pointer to new node
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
dlistint_t *target;

if (h == NULL)
return (NULL);

new_node = create_new_node(n);
if (new_node == NULL)
return (NULL);

if (idx == 0)
return (insert_at_beginning(h, new_node));

target = traverse_to_node(*h, idx);
if (target == NULL)
{
free(new_node);
return (NULL);
}

return (insert_before_node(target, new_node));
}
