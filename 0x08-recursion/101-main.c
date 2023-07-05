#include <stdio.h>
#include "main.h"

int main(void)
{
    int r;

    r = wildcmp("main.c", "***");
    printf("%d\n", r);

    r = wildcmp("main.c", "m.*c");
    printf("%d\n", r);

    r = wildcmp("main.c", "**.*c");
    printf("%d\n", r);

    r = wildcmp("main-main.c", "ma*in.c");
    printf("%d\n", r);

    r = wildcmp("main.c", "main.*");
    printf("%d\n", r);

    r = wildcmp("main.c", "*.*");
    printf("%d\n", r);

    r = wildcmp("main.c", "m*n.c");
    printf("%d\n", r);

    r = wildcmp("main.c", "m*.c");
    printf("%d\n", r);

    r = wildcmp("abc", "*b");
    printf("%d\n", r);

    return 0;
}
