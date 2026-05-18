#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

void print_list(listint_t *head)
{
while (head != NULL)
{
printf("%d ", head->n);
head = head->next;
}
printf("\n");
}

int main(void)
{
listint_t *head = NULL;
listint_t *node1, *node2, *node3;
listint_t *result;

/* Manually create a list: 10 -> 20 -> 30 */
node1 = malloc(sizeof(listint_t));
node2 = malloc(sizeof(listint_t));
node3 = malloc(sizeof(listint_t));

if (!node1 || !node2 || !node3)
return (1);

node1->n = 10;
node1->next = node2;
node2->n = 20;
node2->next = node3;
node3->n = 30;
node3->next = NULL;
head = node1;

printf("Original list: ");
print_list(head);

/* Insert at index 1 (between 10 and 20) */
result = insert_nodeint_at_index(&head, 1, 15);
printf("After insert at index 1: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

/* Insert at beginning */
result = insert_nodeint_at_index(&head, 0, 5);
printf("After insert at index 0: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

/* Insert at end */
result = insert_nodeint_at_index(&head, 5, 35);
printf("After insert at index 5: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

/* Invalid index */
result = insert_nodeint_at_index(&head, 10, 99);
printf("After invalid index 10: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed (correct)");

free_listint2(&head);
return (0);
}
