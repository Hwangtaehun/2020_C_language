#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, weight;

    while(1)
    {
        printf("2진수로 변환할 10진 정수를 입력하세요. (종료는 0) ==> ");
        scanf("%d", &num);
        if(num == 0)
            break;
        weight = 2;
        while(weight <= num)
        {
            weight *= 2;
        }
        weight /= 2;
        printf("\n 10 진수 %7d의 2 진수는 --->", num);
        while(weight != 0)
        {
           printf("%2d", num/weight);
           num %= weight;
           weight /= 2;
        }
        printf("\n\n");
    }
    return 0;
}
