#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, cnt = 0;

    for(i = 2; i <= 100 ; i++)
    {
        for(j = 2; j < i; j++)
        {
           if(i%j ==0)
            break;
        }
        if(i == j)
        {
            printf("%5d", i);
            cnt++;
            if(cnt%5 == 0)
            {
                putchar('\n');
            }
        }
    }
    printf("\n소수의 수는 %d개 입니다.\n", cnt);
    return 0;
}
