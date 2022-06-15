#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, m;
    i = m = 0;

    while( i < 100 )
    {
        i++;
        m += i;
    }
    printf("첫 번째 합 = %d\n", m);

    i = m = 0;
    while( i++ < 100 )
    {
        m += i;
    }
    printf("두 번째 합 = %d\n", m);

    i = m = 0;
    while( ++i < 100 )
    {
        m += i;
    }
    printf("세 번째 합 = %d\n", m);

    return 0;
}
