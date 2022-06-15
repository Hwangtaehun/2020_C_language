#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=1, b=0;

dasi:
    a++;
    b += a;
    a++;
    b -= a;
    if(a <100)
        goto dasi;

    printf("total = %d\n", b);
    printf("program end\n");
}
