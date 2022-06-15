#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c, d;
    for(c = 0; c < 26/2; c++)

    //for(c = 'A'; c <= 'Z'; c++)
    {
        for(d= 1; d<=26 - c ; d++)
        {
            putchar(' ');
        }
        for(d = 'A'; d <= c*2+'A'; d++)
        {
            putchar(d);
        }
        putchar('\n');
    }

    return 0;
}
