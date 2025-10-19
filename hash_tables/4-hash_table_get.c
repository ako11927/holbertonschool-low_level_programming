#include "hash_tables.h"

/**
 * hash_table_get - Retrieve the value for a key
 * @ht: hash table
 * @key: key to look up
 * Return: value pointer (do not free) or NULL if not found
 */
char *hash_table_get(const hash_table_t *ht, const char *key)
{
	unsigned long int idx;
	hash_node_t *cur;

	if (!ht || !key || *key == '\0')
		return (NULL);

	idx = key_index((const unsigned char *)key, ht->size);

	for (cur = ht->array[idx]; cur; cur = cur->next)
		if (strcmp(cur->key, key) == 0)
			return (cur->value);

	return (NULL);
}
