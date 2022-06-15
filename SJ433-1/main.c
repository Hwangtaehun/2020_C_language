#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a = 0, b = 0, c = 0;
dasi:
    a++;
    b += a;
    c += b;
    if(a < 10)
        goto dasi;

    printf("bÇÕ = %d\n", b);
    printf("cÇÕ = %d\n", c);
    printf("program end\n");
    return 0;
}
