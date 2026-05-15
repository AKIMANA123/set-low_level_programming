#include <stdlib.h>
#include <string.h>
#include "lists.h"

/**
 * create_node - creates a new node
 * @str: string to be added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
static list_t *create_node(const char *str)
{
list_t *new_node;
unsigned int len = 0;

/* Calculate length of the string manually */
while (str[len] != '\0')
len++;

/* Allocate memory for new node */
new_node = malloc(sizeof(list_t));
if (new_node == NULL)
return (NULL);

/* Duplicate the string */
new_node->str = strdup(str);
if (new_node->str == NULL)
{
free(new_node);
return (NULL);
}

new_node->len = len;
new_node->next = NULL;

return (new_node);
}

/**
 * add_node_end - adds a new node at the end of a list_t list
 * @head: double pointer to the head of the list
 * @str: string to be added to the new node
 *
 * Return: address of the new element, or NULL if it failed
 */
list_t *add_node_end(list_t **head, const char *str)
{
list_t *new_node;
list_t *temp;

if (head == NULL || str == NULL)
return (NULL);

new_node = create_node(str);
if (new_node == NULL)
return (NULL);

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

temp->next = new_node;
return (new_node);
}
