#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

static const listint_t *has_loop(const listint_t *head)
{
const listint_t *slow = head;
const listint_t *fast = head;

while (fast != NULL && fast->next != NULL)
{
slow = slow->next;
fast = fast->next->next;
if (slow == fast)
return (slow);
}
return (NULL);
}

static const listint_t *find_loop_start(const listint_t *head,
const listint_t *meet)
{
const listint_t *slow = head;
const listint_t *fast = meet;

while (slow != fast)
{
slow = slow->next;
fast = fast->next;
}
return (slow);
}

static size_t print_normal(const listint_t *head)
{
size_t count = 0;

while (head != NULL)
{
printf("[%p] %d\n", (void *)head, head->n);
count++;
head = head->next;
}
return (count);
}

static size_t print_list_with_loop(const listint_t *head,
	const listint_t *loop_start)
{
const listint_t *current = head;
size_t count = 0;

while (current != loop_start)
{
printf("[%p] %d\n", (void *)current, current->n);
count++;
current = current->next;
}

do {
printf("[%p] %d\n", (void *)current, current->n);
count++;
current = current->next;
} while (current != loop_start);

printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
return (count);
}

size_t print_listint_safe(const listint_t *head)
{
const listint_t *meet;
const listint_t *loop_start;

if (head == NULL)
return (0);

meet = has_loop(head);
if (meet == NULL)
return (print_normal(head));

loop_start = find_loop_start(head, meet);
return (print_list_with_loop(head, loop_start));
}
