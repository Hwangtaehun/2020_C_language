#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b= 0;
dasi:
    a++;
    b += a;
    if(a<100)
        goto dasi;

    printf("гу = %d\n", b);
    printf("program end\n");
    return 0;
}
