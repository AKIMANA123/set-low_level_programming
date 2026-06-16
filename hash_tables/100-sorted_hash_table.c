#include "hash_tables.h"

/**
 * shash_table_create - creates a sorted hash table
 * @size: size of the array
 *
 * Return: pointer to the newly created sorted hash table, or NULL on failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
shash_table_t *new_table;
unsigned long int i;

if (size == 0)
return (NULL);

new_table = malloc(sizeof(shash_table_t));
if (new_table == NULL)
return (NULL);

new_table->array = malloc(sizeof(shash_node_t *) * size);
if (new_table->array == NULL)
{
free(new_table);
return (NULL);
}

for (i = 0; i < size; i++)
new_table->array[i] = NULL;

new_table->size = size;
new_table->shead = NULL;
new_table->stail = NULL;

return (new_table);
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

/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: the sorted hash table
 * @key: the key to look for
 *
 * Return: value associated with the key, or NULL if key couldn't be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
shash_node_t *current;
unsigned long int index;

if (ht == NULL || key == NULL || *key == '\0')
return (NULL);

index = key_index((unsigned char *)key, ht->size);

current = ht->array[index];
while (current != NULL)
{
if (strcmp(current->key, key) == 0)
return (current->value);
current = current->next;
}

return (NULL);
}

/**
 * shash_table_print - prints a sorted hash table
 * @ht: the sorted hash table
 */
void shash_table_print(const shash_table_t *ht)
{
shash_node_t *current;
int first = 1;

if (ht == NULL)
return;

printf("{");
current = ht->shead;
while (current != NULL)
{
if (!first)
printf(", ");
printf("'%s': '%s'", current->key, current->value);
first = 0;
current = current->snext;
}
printf("}\n");
}

/**
 * shash_table_print_rev - prints a sorted hash table in reverse order
 * @ht: the sorted hash table
 */
void shash_table_print_rev(const shash_table_t *ht)
{
shash_node_t *current;
int first = 1;

if (ht == NULL)
return;

printf("{");
current = ht->stail;
while (current != NULL)
{
if (!first)
printf(", ");
printf("'%s': '%s'", current->key, current->value);
first = 0;
current = current->sprev;
}
printf("}\n");
}
