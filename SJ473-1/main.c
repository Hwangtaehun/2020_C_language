#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, min = 999, max = 0, cnt =0;
    printf("정수를 입력, 종료하려면 999를 입력하세요.\n" );
    while(scanf("%d", &n), n != 999)
    {
        cnt++;
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
    }
    printf("입력된 %d 개 자료의 최소 값 = %d\n", cnt, min);
    printf("입력된 %d 개 자료의 최대 값 = %d\n", cnt, max);
    return 0;
}
