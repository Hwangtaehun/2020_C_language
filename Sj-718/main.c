#include <stdio.h>
#include <stdlib.h>

int Divisor(int k);

int main()
{
    int n, tot = 0;

    scanf("%d", &n);
    tot = Divisor(n);

    printf("\n«’∞Ë = %d\n", tot);
    return 0;
}

int Divisor(int k){
    int i, sum=0;

    for(i = 1; i <= k; i++)
    {
        if(k % i == 0)
        {
            printf("%5d", i);
            sum += i;
        }
    }
    return sum;
}
