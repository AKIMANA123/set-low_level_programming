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
listint_t *empty = NULL;
listint_t *result;
int i;

/* Test 1: Insert at beginning (index 0) */
for (i = 10; i <= 30; i += 10)
add_nodeint_end(&head, i);
printf("Original list: ");
print_list(head);

result = insert_nodeint_at_index(&head, 0, 5);
printf("After insert at index 0: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

/* Test 2: Insert at end */
result = insert_nodeint_at_index(&head, 4, 40);
printf("After insert at index 4: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

/* Test 3: Invalid index (beyond list length) */
result = insert_nodeint_at_index(&head, 10, 99);
printf("After invalid index 10: ");
print_list(head);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed (correct)");

/* Test 4: Insert into empty list at index 0 */
result = insert_nodeint_at_index(&empty, 0, 100);
printf("Insert into empty list at index 0: ");
print_list(empty);
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

free_listint2(&head);
free_listint2(&empty);
return (0);
}
