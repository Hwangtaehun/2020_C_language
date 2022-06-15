#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j;

    for(i = 1; i <= 4; i++){
        for(j = 1; j <= i ; j++){
            putchar('*');
        }
        putchar('\n');
    }

    return 0;
}
