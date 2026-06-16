#include "hash_tables.h"

/**
 * update_existing_shash - updates the value of an existing key
 * @node: the node to update
 * @value: new value
 *
 * Return: 1 on success, 0 on failure
 */
static int update_existing_shash(shash_node_t *node, const char *value)
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
static shash_node_t *create_shash_node(const char *key, const char *value)
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
 * shash_table_set - adds an element to the sorted hash table
 * @ht: the sorted hash table
 * @key: the key
 * @value: the value
 *
 * Return: 1 if succeeded, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
shash_node_t *current, *new_node;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
return (0);

index = key_index((unsigned char *)key, ht->size);

current = ht->array[index];
while (current != NULL)
{
if (strcmp(current->key, key) == 0)
return (update_existing_shash(current, value));
current = current->next;
}

new_node = create_shash_node(key, value);
if (new_node == NULL)
return (0);

new_node->next = ht->array[index];
ht->array[index] = new_node;

insert_sorted(ht, new_node);
return (1);
}
