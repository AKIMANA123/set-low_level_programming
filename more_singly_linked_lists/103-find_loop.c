#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list
 * @head: pointer to the head of the list
 *
 * Description: Uses Floyd's cycle detection algorithm
 * (tortoise and hare) to detect if the linked list
 * contains a loop, and returns the start node of the loop.
 *
 * Return: address of the node where the loop starts,
 *         or NULL if there is no loop
 */
listint_t *find_listint_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;

if (head == NULL)
return (NULL);

/* Detect if there's a loop using Floyd's algorithm */
while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
/* Loop detected, find the start of the loop */
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}
}

return (NULL);
}
