#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, n = 2, sw;
    int prime[100] = { 2, 3 };
    for(i = 5; i < 100 ; i += 2)
    {
        sw = 0;
        for(j = 1; j < n; j++)
        {
           if(i % prime[j] ==0)
           {
            sw = 1;
            break;
           }
        }
        if(sw == 0)
        {
           prime[n] = i;
           n++;
        }
    }
    for(i=0; i < n; i++)
    {
        printf("%5d", prime[i]);
        if(i%5 == 4)
        {
            putchar('\n');
        }
    }
    printf("\n소수의 수는 %d개 입니다.\n", n);
    return 0;
}
