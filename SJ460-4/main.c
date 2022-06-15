#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, tot;

    for(i = 2; i <= 10000 ; i++)
    {
        tot = 0;
        for( j = 1; j <= i/2 ; j++ )
        {
            if( i % j == 0 )
            {
                tot += j;
            }
        }
        if( tot == i )
        {
            printf("\n %d은 완전수 , 합 = %d\n", i, tot);
        }
    }

    return 0;
}
