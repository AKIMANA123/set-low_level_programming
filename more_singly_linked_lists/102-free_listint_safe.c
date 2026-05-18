#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * free_listint_safe - frees a listint_t list safely (handles loops)
 * @h: double pointer to the head of the list
 *
 * Description: Frees a list, even if it contains a loop.
 * Uses Floyd's cycle detection to find and handle loops.
 * The head is set to NULL after freeing.
 *
 * Return: size of the list that was freed
 */
size_t free_listint_safe(listint_t **h)
{
listint_t *slow, *fast, *temp;
size_t count = 0;
int loop_found = 0;

if (h == NULL || *h == NULL)
return (0);

/* Detect if there's a loop using Floyd's algorithm */
slow = *h;
fast = *h;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
loop_found = 1;
break;
}
}

if (loop_found)
{
/* Find the start of the loop */
slow = *h;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
/* slow is now the start of the loop */

/* First, free nodes before the loop */
while (*h != slow)
{
temp = *h;
*h = (*h)->next;
free(temp);
count++;
}

/* Free nodes in the loop, but break when we complete the circle */
temp = slow;
do {
temp = temp->next;
free(slow);
count++;
slow = temp;
} while (slow != *h);
}
else
{
/* No loop - free normally */
while (*h != NULL)
{
temp = *h;
*h = (*h)->next;
free(temp);
count++;
}
}

*h = NULL;
return (count);
}
