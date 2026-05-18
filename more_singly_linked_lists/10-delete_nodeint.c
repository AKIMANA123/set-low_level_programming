#include <stdlib.h>
#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t list
 * @head: double pointer to the head of the list
 * @index: index of the node to delete (starts at 0)
 *
 * Return: 1 on success, -1 on failure
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
listint_t *temp;
listint_t *prev;
unsigned int i;

if (head == NULL || *head == NULL)
return (-1);

temp = *head;

/* Delete at beginning (index 0) */
if (index == 0)
{
*head = (*head)->next;
free(temp);
return (1);
}

/* Traverse to the node to delete */
for (i = 0; i < index; i++)
{
if (temp == NULL)
return (-1);
prev = temp;
temp = temp->next;
}

if (temp == NULL)
return (-1);

/* Delete the node */
prev->next = temp->next;
free(temp);

return (1);
}
