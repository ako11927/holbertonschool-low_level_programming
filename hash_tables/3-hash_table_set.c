#include "hash_tables.h"

/**
 * create_node - creates a new hash node
 * @key: key string (must be duplicated)
 * @value: value string (must be duplicated)
 *
 * Return: pointer to new node, or NULL if it fails
 */
hash_node_t *create_node(const char *key, const char *value)
{
	hash_node_t *node;

	node = malloc(sizeof(hash_node_t));
	if (!node)
		return (NULL);

	node->key = strdup(key);
	if (!node->key)
	{
		free(node);
		return (NULL);
	}

	node->value = strdup(value);
	if (!node->value)
	{
		free(node->key);
		free(node);
		return (NULL);
	}

	node->next = NULL;
	return (node);
}

/**
 * hash_table_set - Add or update an element in a hash table
 * @ht: hash table
 * @key: key (must not be empty)
 * @value: value (duplicated)
 *
 * Return: 1 on success, 0 on failure
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *vdup;

	if (!ht || !key || *key == '\0' || !value)
		return (0);

	idx = key_index((const unsigned char *)key, ht->size);
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

	node = create_node(key, value);
	if (!node)
		return (0);

	node->next = ht->array[idx];
	ht->array[idx] = node;
	return (1);
}
