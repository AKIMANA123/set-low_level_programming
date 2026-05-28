#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
dlistint_t *head = NULL;
int sum;

/* Test 1: Empty list */
sum = sum_dlistint(head);
printf("Empty list sum: %d\n", sum);

/* Test 2: Single node */
add_dnodeint_end(&head, 42);
sum = sum_dlistint(head);
printf("Single node (42): %d\n", sum);

/* Test 3: Add more nodes */
add_dnodeint_end(&head, 58);
add_dnodeint_end(&head, 100);
sum = sum_dlistint(head);
printf("Three nodes (42, 58, 100): %d\n", sum);

/* Test 4: Negative numbers */
free_dlistint(head);
head = NULL;
add_dnodeint_end(&head, -10);
add_dnodeint_end(&head, 20);
add_dnodeint_end(&head, -30);
sum = sum_dlistint(head);
printf("With negatives (-10, 20, -30): %d\n", sum);

free_dlistint(head);
return (0);
}
