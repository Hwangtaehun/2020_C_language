#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    scanf("%d", &n);

    if(n%2 == 0)
    {
        printf("짝수입니다.");
    }
    else
    {
        printf("홀수입니다.");
    }

    return 0;
}
