#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: length
 */
static int _strlen(char *s)
{
	int len = 0;

	if (s == NULL)
		return (0);

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strcpy - copies a string
 * @dest: destination buffer
 * @src: source string
 * Return: dest
 */
static char *_strcpy(char *dest, char *src)
{
	int i = 0;

	if (dest == NULL || src == NULL)
		return (dest);

	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * new_dog - creates a new dog, storing copies of name and owner
 * @name: dog's name
 * @age: dog's age
 * @owner: dog's owner
 *
 * Return: pointer to new dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	char *ncopy, *ocopy;
	int ln, lo;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(*d));
	if (d == NULL)
		return (NULL);

	ln = _strlen(name);
	lo = _strlen(owner);

	ncopy = malloc(ln + 1);
	if (ncopy == NULL)
	{
		free(d);
		return (NULL);
	}

	ocopy = malloc(lo + 1);
	if (ocopy == NULL)
	{
		free(ncopy);
		free(d);
		return (NULL);
	}

	_strcpy(ncopy, name);
	_strcpy(ocopy, owner);

	d->name = ncopy;
	d->age = age;
	d->owner = ocopy;

	return (d);
}
