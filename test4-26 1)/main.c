#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b = 1, c = 1;

    for(a = 1; a <= 6; a++)
    {
        c += a;
        b += c;
    }

    printf("hap = %d\n", b);

    return 0;
}
