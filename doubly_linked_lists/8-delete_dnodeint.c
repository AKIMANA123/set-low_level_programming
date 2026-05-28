#include <stdlib.h>
#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at index of a dlistint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
dlistint_t *temp;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

temp = *head;

/* Delete at beginning (index 0) */
if (index == 0)
{
*head = (*head)->next;
if (*head != NULL)
(*head)->prev = NULL;
free(temp);
return (1);
}

/* Traverse to the node to delete */
for (i = 0; i < index; i++)
{
if (temp == NULL)
return (-1);
temp = temp->next;
}

if (temp == NULL)
return (-1);

/* Update pointers to bypass the node */
if (temp->prev != NULL)
temp->prev->next = temp->next;

if (temp->next != NULL)
temp->next->prev = temp->prev;

free(temp);
return (1);
}
