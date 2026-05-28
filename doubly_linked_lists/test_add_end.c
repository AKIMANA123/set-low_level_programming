#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(dlistint_t *head)
{
while (head != NULL)
{
printf("%d ", head->n);
head = head->next;
}
printf("\n");
}

void print_list_reverse(dlistint_t *head)
{
/* Go to tail first */
if (head == NULL)
return;
while (head->next != NULL)
head = head->next;

/* Print backwards */
while (head != NULL)
{
printf("%d ", head->n);
head = head->prev;
}
printf("\n");
}

int main(void)
{
dlistint_t *head = NULL;
dlistint_t *result;

/* Test 1: Add to empty list */
result = add_dnodeint_end(&head, 42);
printf("After adding to empty list: ");
print_list(head);
printf("Returned value: %d\n", result ? result->n : -1);

/* Test 2: Add to non-empty list */
add_dnodeint_end(&head, 10);
add_dnodeint_end(&head, 20);
add_dnodeint_end(&head, 30);
printf("After adding multiple nodes: ");
print_list(head);

/* Test 3: Verify prev pointers work for backward traversal */
printf("Forward traversal: ");
print_list(head);
printf("Backward traversal: ");
print_list_reverse(head);

return (0);
}
