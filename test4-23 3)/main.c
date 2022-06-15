#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, c;

    for(a = 65; a <= 90; a++)
    {
        for(c= 65; c<= 155 - a ; c++)
        {
            putchar(' ');
        }
        for(c = 65; c <= a ; c++)
        {
            printf("%c", c);
        }
        putchar('\n');
    }

    return 0;
}
