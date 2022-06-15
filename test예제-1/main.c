#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a = 1, b = 0, c = -2, d = 0;

Add:
    a += 2;
    b += a;
    if(a <= 99)
        goto Add;

Min:
    c += -2;
    d += c;
    if(c > -100)
        goto Min;

    printf("total = %d\n", b + d);
    printf("program end \n");
    return 0;
}
