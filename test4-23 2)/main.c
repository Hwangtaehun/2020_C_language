#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, d;

    for(c = 'A'; c <= 'Z'; c++)
    {
        for(d = 'A'; d <= c ; d++)
        {
            putchar(d);
        }
        putchar('\n');
    }

    return 0;
}
