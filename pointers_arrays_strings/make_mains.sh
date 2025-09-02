#!/usr/bin/env bash
# Create all Holberton-style test mains + local _putchar.c

set -e

# _putchar.c (used by tasks 3,4,6,7)
cat > _putchar.c <<'EOF'
#include <unistd.h>
int _putchar(char c)
{
    return (write(1, &c, 1));
}
EOF

cat > 0-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    int n = 402;
    printf("n=%d\n", n);
    reset_to_98(&n);
    printf("n=%d\n", n);
    return (0);
}
EOF

cat > 1-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    int a = 98, b = 42;
    printf("a=%d, b=%d\n", a, b);
    swap_int(&a, &b);
    printf("a=%d, b=%d\n", a, b);
    return (0);
}
EOF

cat > 2-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char *str = "My first strlen!";
    int len = _strlen(str);
    printf("%d\n", len);
    return (0);
}
EOF

cat > 3-main.c <<'EOF'
#include "main.h"
int main(void)
{
    char *str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    _puts(str);
    return (0);
}
EOF

cat > 4-main.c <<'EOF'
#include "main.h"
int main(void)
{
    char *str = "I do not fear computers. I fear the lack of them - Isaac Asimov";
    print_rev(str);
    return (0);
}
EOF

cat > 5-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s[10] = "My School";
    printf("%s\n", s);
    rev_string(s);
    printf("%s\n", s);
    return (0);
}
EOF

cat > 6-main.c <<'EOF'
#include "main.h"
int main(void)
{
    char *str = "0123456789";
    puts2(str);
    return (0);
}
EOF

cat > 7-main.c <<'EOF'
#include "main.h"
int main(void)
{
    char *str = "0123456789";
    puts_half(str);
    return (0);
}
EOF

cat > 8-main.c <<'EOF'
#include "main.h"
int main(void)
{
    int array[5];
    array[0] = 98;
    array[1] = 402;
    array[2] = -198;
    array[3] = 298;
    array[4] = -1024;
    print_array(array, 5);
    return (0);
}
EOF

cat > 9-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s1[98];
    char *ptr;
    ptr = _strcpy(s1, "First, solve the problem. Then, write the code\n");
    printf("%s", s1);
    printf("%s", ptr);
    return (0);
}
EOF

cat > 100-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    int nb;
    nb = _atoi("98");                           printf("%d\n", nb);
    nb = _atoi("-402");                         printf("%d\n", nb);
    nb = _atoi("          ------++++++-----+++++--98"); printf("%d\n", nb);
    nb = _atoi("214748364");                    printf("%d\n", nb);
    nb = _atoi("0");                            printf("%d\n", nb);
    nb = _atoi("Suite 402");                    printf("%d\n", nb);
    nb = _atoi("         +      +    -    -98 Battery Street"); printf("%d\n", nb);
    nb = _atoi("---++++ -++ Sui - te -   402 #cisfun :)");      printf("%d\n", nb);
    return (0);
}
EOF

echo "All mains and _putchar.c created ✅"
