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
        for(j = 1; j <= i * 2 -1 ; j++)
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
        for(j = 1; j <= i * 2 -1; j++)
        {
            putchar('*');
        }
        putchar('\n');
    }
    char cc='A';
    for(i = 1; i <= 4; i++)
    {
        for(j = 1; j <= (5 - i); j++)
        {
            putchar(' ');
        }
        for(j = 1; j <= i * 2 -1 ; j++)
        {
            putchar(cc);
            cc++;
        }
        putchar('\n');
    }
     for(i = 3; i >= 1; i--)
    {
        for(j = 1; j <= (5 - i); j++)
        {
            putchar(' ');
        }
        for(j = 1; j <= i * 2 -1 ; j++)
        {
            putchar(cc);
            cc++;
        }
        putchar('\n');
    }
    return 0;
}
