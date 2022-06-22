#include <stdio.h>
#include <stdlib.h>

int Divisor2(int k);

int main()
{
    int i, tot;
    for(i = 2; i <= 10000 ; i++)
    {
        tot = Divisor2( i );
        if( tot == i )
        {
            printf("\n %d은 완전수 , 합 = %d\n", i, tot);
        }
    }

    return 0;
}

int Divisor2(int k){
    int i, tot = 0;
    for( i = 1; i <= k/2 ; i++ )
    {
        if( k % i == 0 )
        {
            tot += i;
        }
    }
    return tot;
}
