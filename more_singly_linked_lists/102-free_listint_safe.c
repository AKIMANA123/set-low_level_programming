#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * detect_loop - detects if a linked list has a loop
 * @head: pointer to the head of the list
 *
 * Description: Uses Floyd's cycle detection algorithm
 * to find a loop in the linked list.
 *
 * Return: pointer to meeting point if loop exists, NULL otherwise
 */
static listint_t *detect_loop(listint_t *head)
{
listint_t *slow = head;
listint_t *fast = head;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
return (slow);
}
return (NULL);
}

/**
 * find_and_free_loop - finds loop start and frees nodes in loop
 * @h: double pointer to the head of the list
 * @meet: meeting point from Floyd's algorithm
 *
 * Return: number of nodes freed
 */
static size_t find_and_free_loop(listint_t **h, listint_t *meet)
{
listint_t *slow = *h;
listint_t *fast = meet;
listint_t *temp;
size_t count = 0;

/* Find the start of the loop */
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}

/* Free nodes before the loop */
while (*h != slow)
{
temp = *h;
*h = (*h)->next;
free(temp);
count++;
}

/* Free nodes in the loop */
temp = slow;
do {
temp = temp->next;
free(slow);
count++;
slow = temp;
} while (slow != *h);

return (count);
}

/**
 * free_normal_list - frees a list without a loop
 * @h: double pointer to the head of the list
 *
 * Return: number of nodes freed
 */
static size_t free_normal_list(listint_t **h)
{
listint_t *temp;
size_t count = 0;

while (*h != NULL)
{
temp = *h;
*h = (*h)->next;
free(temp);
count++;
}
return (count);
}

/**
 * free_listint_safe - frees a listint_t list safely
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
listint_t *meet;
size_t count = 0;

if (h == NULL || *h == NULL)
return (0);

meet = detect_loop(*h);
if (meet == NULL)
return (free_normal_list(h));

count = find_and_free_loop(h, meet);
*h = NULL;
return (count);
}
