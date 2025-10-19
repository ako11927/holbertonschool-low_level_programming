#ifndef HASH_TABLES_H
#define HASH_TABLES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string (unique in the HashTable)
 * @value: The value corresponding to a key
 * @next: A pointer to the next node of the list
 */
typedef struct hash_node_s
{
	char *key;
	char *value;
	struct hash_node_s *next;
} hash_node_t;

/**
 * struct hash_table_s - Hash table data structure
 * @size: The size of the array
 * @array: An array of size @size
 * Each cell is a pointer to the first node of a linked list (chaining)
 */
typedef struct hash_table_s
{
	unsigned long int size;
	hash_node_t **array;
} hash_table_t;

/* 0 */
hash_table_t *hash_table_create(unsigned long int size);

/* 1 */
unsigned long int hash_djb2(const unsigned char *str);

/* 2 */
unsigned long int key_index(const unsigned char *key, unsigned long int size);

/* 3 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value);

/* 4 */
char *hash_table_get(const hash_table_t *ht, const char *key);

/* 5 */
void hash_table_print(const hash_table_t *ht);

/* 6 */
void hash_table_delete(hash_table_t *ht);

#endif /* HASH_TABLES_H */
