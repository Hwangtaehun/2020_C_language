#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , min = 999, max = 0, cnt = 0, tot = 0;
    double av;

    printf("정수 입력, 종료하려면 ^Z을 입력하세요. \n");
    while(scanf("%d", &n) != EOF)
     {
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
        tot += n;
        cnt++;
    }

    av = (double)tot / (double)cnt;
    printf("\n입력된 %d 개 자료의 최소값 = %d\n", cnt, min);
    printf("입력된 %d 개 자료의 최대값 = %d\n", cnt, max);
    printf("입력된 %d 개 자료의 합계 = %d\n", cnt, tot);
    printf("입력된 %d 개 자료의 평균 = %.2f\n", cnt, av);
    return 0;
}
