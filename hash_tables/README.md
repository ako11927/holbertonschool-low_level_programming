# Hash Tables Project

## 📘 Description
This project is part of the Holberton School low-level programming curriculum.  
It covers the implementation of **hash tables** in C — a powerful data structure that allows fast data retrieval using keys.

---

## 🎯 Learning Objectives
At the end of this project, you should be able to explain:
- What is a hash function
- What makes a good hash function
- What is a hash table, how it works, and how to use it
- What is a collision and how to handle it (using chaining)
- The advantages and drawbacks of hash tables
- Common use cases of hash tables

---

## 🧩 Data Structures Used
```c
/**
 * struct hash_node_s - Node of a hash table
 * @key: The key, string
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
 * @array: An array of pointers to the first node of each list
 */
typedef struct hash_table_s
{
    unsigned long int size;
    hash_node_t **array;
} hash_table_t;
