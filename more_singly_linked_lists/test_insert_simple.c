#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
listint_t *head = NULL;
listint_t *result;

/* Test 1: Insert into empty list at index 0 */
result = insert_nodeint_at_index(&head, 0, 100);
printf("Insert into empty list at index 0: ");
if (head != NULL)
printf("%d\n", head->n);
else
printf("NULL\n");
printf("Returned: %s\n", result != NULL ? "Success" : "Failed");

free_listint2(&head);
return (0);
}
