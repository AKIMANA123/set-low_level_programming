#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * has_loop - detects if a linked list has a loop
 * @head: pointer to the head of the list
 *
 * Return: pointer to meeting point if loop exists, NULL otherwise
 */
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

/**
 * find_loop_start - finds the start node of a loop
 * @head: pointer to the head of the list
 * @meet: meeting point from Floyd's algorithm
 *
 * Return: pointer to the start of the loop
 */
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

/**
 * print_normal - prints a list without a loop
 * @head: pointer to the head of the list
 *
 * Return: number of nodes printed
 */
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

/**
 * print_list_with_loop - prints a list that has a loop
 * @head: pointer to the head of the list
 * @loop_start: pointer to the start of the loop
 *
 * Return: number of nodes printed
 */
static size_t print_list_with_loop(const listint_t *head,
   const listint_t *loop_start)
{
const listint_t *current = head;
size_t count = 0;

/* Print nodes before the loop */
while (current != loop_start)
{
printf("[%p] %d\n", (void *)current, current->n);
count++;
current = current->next;
}

/* Print nodes in the loop */
do {
printf("[%p] %d\n", (void *)current, current->n);
count++;
current = current->next;
} while (current != loop_start);

/* Print loop indication */
printf("-> [%p] %d\n", (void *)loop_start, loop_start->n);
return (count);
}

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: pointer to the head of the list
 *
 * Return: number of nodes in the list
 */
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
