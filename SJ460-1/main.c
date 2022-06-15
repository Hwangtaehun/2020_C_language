#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, max, min;
    max=0;
    min=999;

    for(i = 1; i <= 5; i++)
    {
        scanf("%d", &n);
        if(max < n)
        {
            max = n;
            continue;
        }
        if( min > n)
        {
            min = n;
        }
    }

    printf("최대값 = %d, 최소값 = %d\n", max, min);

    return 0;
}
