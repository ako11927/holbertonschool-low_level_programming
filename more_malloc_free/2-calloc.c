#include "main.h"
#include <stdlib.h>
#include <stddef.h>  /* size_t */

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size:  size (in bytes) of each element
 *
 * Return: pointer to allocated zeroed memory, or NULL on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
    size_t total;
    void *p;
    unsigned char *q;
    size_t i;

    if (nmemb == 0 || size == 0)
        return (NULL);

    /* overflow guard without SIZE_MAX */
    if ((size_t)nmemb > ((size_t)-1) / (size_t)size)
        return (NULL);

    total = (size_t)nmemb * (size_t)size;
    p = malloc(total);
    if (p == NULL)
        return (NULL);

    /* zero memory manually (no memset per project rules) */
    q = (unsigned char *)p;
    for (i = 0; i < total; i++)
        q[i] = 0;

    return (p);
}
