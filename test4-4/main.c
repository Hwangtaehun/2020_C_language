#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;

    scanf("%d", &n);

    if(n%3 == 0)
    {
        printf("3의 배수입니다.");
    }
    else
    {
        printf("3의 배수가 아닙니다.");
    }

    return 0;
}
