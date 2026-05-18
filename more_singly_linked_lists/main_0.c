#include <stdio.h>
#include <stdlib.h>
#include "lists.h"

/**
 * main - check the code
 *
 * Return: Always 0.
 */
int main(void)
{
    listint_t *head = NULL;
    listint_t *n;
    
    /* Test insert at index 0 */
    n = insert_nodeint_at_index(&head, 0, 98);
    if (n != NULL)
        printf("Inserted %d at index 0\n", n->n);
    else
        printf("Failed to insert\n");
    
    print_listint(head);
    free_listint2(&head);
    return (0);
}
