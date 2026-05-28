#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
dlistint_t *head = NULL;
dlistint_t *node1, *node2, *node3;

/* Test 1: Free empty list */
printf("Test 1: Free empty list (should not crash)\n");
free_dlistint(NULL);
printf("PASS: No crash\n\n");

/* Test 2: Free list with one node */
printf("Test 2: Free list with one node\n");
head = malloc(sizeof(dlistint_t));
if (head != NULL)
{
head->n = 42;
head->prev = NULL;
head->next = NULL;
free_dlistint(head);
head = NULL;
printf("PASS: Single node freed\n\n");
}

/* Test 3: Free list with multiple nodes */
printf("Test 3: Free list with multiple nodes\n");
node1 = malloc(sizeof(dlistint_t));
node2 = malloc(sizeof(dlistint_t));
node3 = malloc(sizeof(dlistint_t));

if (node1 && node2 && node3)
{
node1->n = 10;
node1->prev = NULL;
node1->next = node2;

node2->n = 20;
node2->prev = node1;
node2->next = node3;

node3->n = 30;
node3->prev = node2;
node3->next = NULL;

head = node1;
free_dlistint(head);
head = NULL;
printf("PASS: Multiple nodes freed\n");
}

return (0);
}
