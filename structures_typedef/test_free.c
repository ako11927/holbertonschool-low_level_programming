#include "dog.h"
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    dog_t *d = new_dog("Poppy", 3.5, "Bob");
    if (d == NULL)
        return (1);

    printf("%s %.1f %s\n", d->name, d->age, d->owner);
    free_dog(d);
    return (0);
}
