#include <stdio.h>
#include "hash_tables.h"

/**
 * main - simple test for hash table project
 *
 * Return: Always 0.
 */
int main(void)
{
    hash_table_t *ht;

    ht = hash_table_create(1024);
    hash_table_set(ht, "betty", "cool");
    hash_table_set(ht, "python", "awesome");
    hash_table_set(ht, "C", "is fun");

    hash_table_print(ht);
    hash_table_delete(ht);

    return (0);
}
