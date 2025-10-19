#include "hash_tables.h"

/**
 * key_index - Get the index for a key
 * @key: key (non-NULL)
 * @size: array size
 * Return: index in range [0, size)
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
