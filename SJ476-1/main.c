#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, cnt = 0;
    printf("정수 입력, 종료하려면 ^Z을 입력하세요. \n ");
    while(scanf("%d", &n) != EOF)
    {
        cnt++;
        printf("%d는 %d번째 입력된 수 입니다.", n, cnt);
    }
    printf("전체 %d 개 입력 하셨습니다.\n", cnt);
    return 0;
}
