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

    printf("b�� = %d\n", b);
    printf("c�� = %d\n", c);
    printf("program end\n");
    return 0;
}
