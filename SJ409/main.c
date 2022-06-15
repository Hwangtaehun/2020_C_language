#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("정수 2개 입력 : ");
    scanf("%d %d", &a, &b);
    if(a>b)
        c = a;
    else
        c = b;

    printf("큰 수 = %d\n", c);

    printf("작은 수  = %d\n", (a<b) ? a : b);
    return 0;
}
