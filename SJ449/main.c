#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, c = 0;

    for(a = 1; a <= 10; a++)
    {
        b += a;
        c += b;
    }
    printf("гу = %d\n", c);
    return 0;
}
