#include "hash_tables.h"

/**
 * hash_table_create - Create a hash table
 * @size: size of the array
 * Return: pointer to new table, or NULL on error/size==0
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *ht;

	if (size == 0)
		return (NULL);

	ht = malloc(sizeof(*ht));
	if (!ht)
		return (NULL);

	ht->size = size;
	ht->array = calloc(size, sizeof(hash_node_t *));
	if (!ht->array)
	{
		free(ht);
		return (NULL);
	}
	return (ht);
}
