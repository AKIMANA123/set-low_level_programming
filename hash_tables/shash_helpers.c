#include "hash_tables.h"

/**
 * insert_sorted - inserts a node into the sorted linked list
 * @ht: the sorted hash table
 * @new_node: the node to insert
 */
void insert_sorted(shash_table_t *ht, shash_node_t *new_node)
{
shash_node_t *current;

if (ht->shead == NULL)
{
ht->shead = new_node;
ht->stail = new_node;
new_node->sprev = NULL;
new_node->snext = NULL;
return;
}

current = ht->shead;
while (current != NULL && strcmp(current->key, new_node->key) < 0)
current = current->snext;

if (current == NULL)
{
ht->stail->snext = new_node;
new_node->sprev = ht->stail;
new_node->snext = NULL;
ht->stail = new_node;
}
else if (current == ht->shead)
{
new_node->snext = ht->shead;
new_node->sprev = NULL;
ht->shead->sprev = new_node;
ht->shead = new_node;
}
else
{
new_node->snext = current;
new_node->sprev = current->sprev;
current->sprev->snext = new_node;
current->sprev = new_node;
}
}

/**
 * update_existing_shash - updates the value of an existing key
 * @node: the node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
int update_existing_shash(shash_node_t *node, const char *value)
{
free(node->value);
node->value = strdup(value);
if (node->value == NULL)
return (0);
return (1);
}

/**
 * create_shash_node - creates a new sorted hash node
 * @key: the key
 * @value: the value
 *
 * Return: pointer to new node, or NULL on failure
 */
shash_node_t *create_shash_node(const char *key, const char *value)
{
shash_node_t *new_node;

new_node = malloc(sizeof(shash_node_t));
if (new_node == NULL)
return (NULL);

new_node->key = strdup(key);
if (new_node->key == NULL)
{
free(new_node);
return (NULL);
}

new_node->value = strdup(value);
if (new_node->value == NULL)
{
free(new_node->key);
free(new_node);
return (NULL);
}

new_node->next = NULL;
new_node->sprev = NULL;
new_node->snext = NULL;

return (new_node);
}

/**
 * shash_table_delete - deletes a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_delete(shash_table_t *ht)
{
shash_node_t *current, *temp;
unsigned long int i;

if (ht == NULL)
return;

for (i = 0; i < ht->size; i++)
{
current = ht->array[i];
while (current != NULL)
{
temp = current;
current = current->next;
free(temp->key);
free(temp->value);
free(temp);
}
}

free(ht->array);
free(ht);
}
