#include <stdio.h>
#include <stdlib.h>

int aHap(int n);
int bHap(int n);

int main()
{
    int a, b;
    a = aHap(100);
    b = bHap(100);
    printf("a = %d\n", a);
    printf("b = %d\n", b);

    return 0;
}

int aHap(int n)
{
    if(n == 1)
        return 1;
    else
        return(n + bHap(n - 1));
}

int bHap(int n)
{
    int i, tot = 0;
    for(i = 1; i <= n; i++)
        tot += i;
    return tot;
}
