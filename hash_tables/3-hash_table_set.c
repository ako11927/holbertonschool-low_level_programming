#include "hash_tables.h"

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: hash table
 * @key: key (must not be empty)
 * @value: value (duplicated)
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *vdup, *kdup;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);

	/* Update if key already exists in chain */
	cur = ht->array[idx];
	while (cur)
	{
		if (strcmp(cur->key, key) == 0)
		{
			vdup = strdup(value);
			if (!vdup)
				return (0);
			free(cur->value);
			cur->value = vdup;
			return (1);
		}
		cur = cur->next;
	}

	/* Insert new node at head (chaining) */
	node = malloc(sizeof(*node));
	if (!node)
		return (0);

	kdup = strdup(key);
	vdup = strdup(value);
	if (!kdup || !vdup)
	{
		free(node);
		free(kdup);
		free(vdup);
		return (0);
	}
	node->key = kdup;
	node->value = vdup;
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}
