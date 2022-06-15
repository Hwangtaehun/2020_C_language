#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;

    for(i = 1; i <= 5; i++)
    {
        for(j = 1; j <= (5 - i); j++)
        {
            putchar(' ');
        }
        for(j = 1; j <= i; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    for(i = 4; i >= 1; i--)
    {
        for(j = 1; j <= (5 - i); j++)
        {
            putchar(' ');
        }
        for(j = 1; j <= i; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
