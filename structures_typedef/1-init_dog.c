#include "dog.h"
#include <stddef.h>  /* NULL */

/**
 * init_dog - initializes a struct dog
 * @d: pointer to struct dog to initialize
 * @name: name to assign
 * @age: age to assign
 * @owner: owner to assign
 *
 * Return: void
 */
void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		return;

	d->name = name;
	d->age = age;
	d->owner = owner;
}
