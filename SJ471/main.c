#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

int main()
{
    int i, n, min = 999, max = 0;
    printf("정수를 %d개 입력하세요.\n", COUNT);
    for(i = 0; i <COUNT;i++)
    {
        scanf("%d", &n);
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
    }
    printf("입력된 %d 개 자료의 최소 값 = %d\n", COUNT, min);
    printf("입력된 %d 개 자료의 최대 값 = %d\n", COUNT, max);
    return 0;
}
