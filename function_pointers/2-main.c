#include <stdio.h>
#include "function_pointers.h"
int is_98(int e) { return (e == 98); }
int is_strictly_positive(int e) { return (e > 0); }
int abs_is_98(int e) { return (e == 98 || -e == 98); }
int main(void)
{
    int a[20] = {0, -98, 98, 402, 1024, 4096, -1024, -98, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 98};
    printf("%d\n", int_index(a, 20, is_98));
    printf("%d\n", int_index(a, 20, abs_is_98));
    printf("%d\n", int_index(a, 20, is_strictly_positive));
    return (0);
}
