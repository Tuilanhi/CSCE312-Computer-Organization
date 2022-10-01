#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, a, b;

    a = 1;
    b = 1;
    for (i = 0; i < 14; i++)
    {
        a = a + b;
        b = b + a;
    }
    printf("%d\n", a);
    exit(0);
}