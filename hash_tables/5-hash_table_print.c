#include "hash_tables.h"

/**
 * hash_table_print - Print a hash table like a Python dict
 * @ht: hash table
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int i;
	hash_node_t *cur;
	int first = 1;

	if (!ht)
		return;

	printf("{");
	for (i = 0; i < ht->size; i++)
	{
		for (cur = ht->array[i]; cur; cur = cur->next)
		{
			if (!first)
				printf(", ");
			printf("'%s': '%s'", cur->key, cur->value);
			first = 0;
		}
	}
	printf("}\n");
}
