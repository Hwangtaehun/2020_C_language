#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;

    printf("정수 3개 입력 : ");
    scanf("%d %d %d", &a, &b, &c);

    e = ( (d = (a>b)?a:b ) > c) ? d : c;

    printf("큰수 = %d\n", e);
    printf("작은수 = %d\n", ( (d = (a>b)?a:b ) < c) ? d : c);

    return 0;
}
