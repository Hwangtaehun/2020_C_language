#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b =0;
    for(a = 1 ; a <= 100 ; a++)
    {
        b += a;
    }
    printf("гу = %d\n", b);
    return 0;
}
