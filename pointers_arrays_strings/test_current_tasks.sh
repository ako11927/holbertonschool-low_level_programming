#!/usr/bin/env bash
set -e

mkdir -p tests

# ---- 0-main.c (strcat) ----
cat > tests/0-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);
    ptr = _strcat(s1, s2);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);
    return (0);
}
EOF

# ---- 1-main.c (strncat) ----
cat > tests/1-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s1[98] = "Hello ";
    char s2[] = "World!\n";
    char *ptr;

    printf("%s\n", s1);
    printf("%s", s2);
    ptr = _strncat(s1, s2, 1);
    printf("%s\n", s1);
    printf("%s", s2);
    printf("%s\n", ptr);
    ptr = _strncat(s1, s2, 1024);
    printf("%s", s1);
    printf("%s", s2);
    printf("%s", ptr);
    return (0);
}
EOF

# ---- 2-main.c (strncpy) ----
cat > tests/2-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s1[98];
    char *ptr;
    int i;

    for (i = 0; i < 98 - 1; i++)
        s1[i] = '*';
    s1[i] = '\0';
    printf("%s\n", s1);
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 5);
    printf("%s\n", s1);
    printf("%s\n", ptr);
    ptr = _strncpy(s1, "First, solve the problem. Then, write the code\n", 90);
    printf("%s", s1);
    printf("%s", ptr);
    for (i = 0; i < 98; i++)
    {
        if (i % 10) printf(" ");
        if (!(i % 10) && i) printf("\n");
        printf("0x%02x", s1[i]);
    }
    printf("\n");
    return (0);
}
EOF

# ---- 3-main.c (strcmp) ----
cat > tests/3-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s1[] = "Hello";
    char s2[] = "World!";
    printf("%d\n", _strcmp(s1, s2));
    printf("%d\n", _strcmp(s2, s1));
    printf("%d\n", _strcmp(s1, s1));
    return (0);
}
EOF

# ---- 4-main.c (reverse_array) ----
cat > tests/4-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
void print_array(int *a, int n)
{
    int i = 0;
    while (i < n)
    {
        if (i) printf(", ");
        printf("%d", a[i]);
        i++;
    }
    printf("\n");
}
int main(void)
{
    int a[] = {0,1,2,3,4,5,6,7,8,9,98,1024,1337};
    int n = sizeof(a)/sizeof(int);
    print_array(a, n);
    reverse_array(a, n);
    print_array(a, n);
    return (0);
}
EOF

# ---- 5-main.c (string_toupper) ----
cat > tests/5-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char str[] = "Look up!\n";
    char *ptr = string_toupper(str);
    printf("%s", ptr);
    printf("%s", str);
    return (0);
}
EOF

# ---- 6-main.c (cap_string) ----
cat > tests/6-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char str[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\nhello world! hello-world 0123456hello world\thello world.hello world\n";
    char *ptr = cap_string(str);
    printf("%s", ptr);
    printf("%s", str);
    return (0);
}
EOF

# ---- 7-main.c (leet) ----
cat > tests/7-main.c <<'EOF'
#include "main.h"
#include <stdio.h>
int main(void)
{
    char s[] = "Expect the best. Prepare for the worst. Capitalize on what comes.\n";
    char *p = leet(s);
    printf("%s", p);
    printf("%s", s);
    return (0);
}
EOF

echo "Compiling & running…"

gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/0-main.c 0-strcat.c -o tests/0-strcat && tests/0-strcat
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/1-main.c 1-strncat.c -o tests/1-strncat && tests/1-strncat
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/2-main.c 2-strncpy.c -o tests/2-strncpy && tests/2-strncpy
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/3-main.c 3-strcmp.c -o tests/3-strcmp && tests/3-strcmp
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/4-main.c 4-rev_array.c -o tests/4-rev_array && tests/4-rev_array
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/5-main.c 5-string_toupper.c -o tests/5-string_toupper && tests/5-string_toupper
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/6-main.c 6-cap_string.c -o tests/6-cap && tests/6-cap
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 tests/7-main.c 7-leet.c -o tests/7-1337 && tests/7-1337

echo "✅ Done. All current tasks compiled & ran using the correct mains."
