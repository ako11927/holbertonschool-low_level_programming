#include "main.h"
#include <stdlib.h>
#include <stddef.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to zero-initialized memory on success,
 *         or NULL on failure or overflow.
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	size_t total;
	void *ptr;
	unsigned char *p;
	size_t i;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* overflow guard: (size_t)nmemb * (size_t)size must not wrap */
	if ((size_t)nmemb > ((size_t)-1) / (size_t)size)
		return (NULL);

	total = (size_t)nmemb * (size_t)size;

	ptr = malloc(total);
	if (ptr == NULL)
		return (NULL);

	/* zero manually (memset not allowed) */
	p = (unsigned char *)ptr;
	for (i = 0; i < total; i++)
		p[i] = 0;

	return (ptr);
}
