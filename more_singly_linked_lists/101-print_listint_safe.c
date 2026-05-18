#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * print_listint_safe - prints a listint_t linked list safely (handles loops)
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
const listint_t *slow = head;
const listint_t *fast = head;
const listint_t *loop_start = NULL;
size_t count = 0;
size_t loop_count = 0;
int has_loop = 0;

if (head == NULL)
return (0);

/* Detect loop using Floyd's cycle detection algorithm */
while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
{
has_loop = 1;
break;
}
}

if (has_loop)
{
/* Find the start of the loop */
slow = head;
while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
loop_start = slow;

/* Print nodes before the loop */
slow = head;
while (slow != loop_start)
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
slow = slow->next;
}

/* Print nodes in the loop */
slow = loop_start;
do
{
printf("[%p] %d\n", (void *)slow, slow->n);
count++;
slow = slow->next;
loop_count++;
} while (slow != loop_start);

/* Print loop indication */
printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
}
else
{
/* No loop, just print normally */
while (head != NULL)
{
printf("[%p] %d\n", (void *)head, head->n);
count++;
head = head->next;
}
}

return (count);
}
