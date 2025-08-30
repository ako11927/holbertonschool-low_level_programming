#include "main.h"
#include <stdio.h>

int main(void)
{
    /* Task 0 & 1 & 2 */
    printf("_isupper('A')=%d _isupper('a')=%d\n", _isupper('A'), _isupper('a'));
    printf("_isdigit('5')=%d _isdigit('A')=%d\n", _isdigit('5'), _isdigit('A'));
    printf("mul(98, 1024)=%d\n", mul(98, 1024));

    /* Task 3..8 & 10 (use _putchar) */
    print_numbers();
    print_most_numbers();
    more_numbers();
    print_line(5);
    print_diagonal(5);
    print_square(4);
    print_triangle(5);

    return (0);
}
