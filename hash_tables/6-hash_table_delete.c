#include "hash_tables.h"

/**
 * hash_table_delete - Delete a hash table and free all memory
 * @ht: hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur, *next;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		cur = ht->array[i];
		while (cur)
		{
			next = cur->next;
			free(cur->key);
			free(cur->value);
			free(cur);
			cur = next;
		}
	}
	free(ht->array);
	free(ht);
}
