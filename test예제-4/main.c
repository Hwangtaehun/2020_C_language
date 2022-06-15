#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =0, b=0, s=1;

dasi:
    a++;
    b =  b + a*s;
    s = -s;
    if(a < 100)
        goto dasi;

    printf("total = %d\n", b);
    printf("program end\n");
    return 0;
}
