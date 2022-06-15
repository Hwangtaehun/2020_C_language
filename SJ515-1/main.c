#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, num1, n, i;
    char bin[32];
    while(1)
    {
        printf("2진수로 변환할 10진 정수를 입력하세요. (종료는 0) ==> ");
        scanf("%d", &num);
        if(num == 0)
            break;
        n = 0;
        num1 = num;
        while( num != 0)
        {
            bin[n] = num % 2;
            num /= 2;
            n++;
        }
        printf("\n 10 진수 %7d의 2 진수는 --->", num1);
        for(i = n - 1; i >= 0; i--){
            printf("%2d", bin[i]);
        }
        printf("\n\n");
    }
    return 0;
}
