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
    printf("ù ��° �� = %d\n", m);

    i = m = 0;
    while( i++ < 100 )
    {
        m += i;
    }
    printf("�� ��° �� = %d\n", m);

    i = m = 0;
    while( ++i < 100 )
    {
        m += i;
    }
    printf("�� ��° �� = %d\n", m);

    return 0;
}
