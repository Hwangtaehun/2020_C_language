#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n, i, tot = 0;

    scanf("%d", &n);

    for(i = 1; i <= n; i++)
    {
        if(n % i == 0)
        {
            printf("%5d", i);
            tot += i;
        }
    }
    printf("\nÇÔ°è = %d\n", tot);
    return 0;
}
