#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0;
dasi:
    a++;
    if(a % 2 == 0)
        b -= a;
    else
        b += a;
    if(a < 100)
        goto dasi;
    printf("total = %d\n", b);
    printf("program end\n");
    return 0;
}
