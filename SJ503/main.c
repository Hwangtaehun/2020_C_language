#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int k[MAX];
    int i, sum, max, min;
    float av;
    printf(" 정수를 %d 개 입력하세요. \n", MAX);
    for( i = 0 ; i < MAX; i++)
    {
        scanf("%d", &k[i] );
    }
    printf(" 배열에 입력된 내용 출력 \n", MAX);
    for( i = 0 ; i < MAX; i++)
    {
        printf("%5d", k[i]);
    }
     for( i = 0, sum = 0 ; i < MAX; i++)
    {
        sum += k[i];
    }
    av = (float)sum / (float)MAX;

    max = min = k[0];
    for( i = 1 ; i < MAX; i++)
    {
        if(k[i] > max)
            max = k[i];
        if(k[i] < min)
            min = k[i];
    }
    printf("합은 %d입니다.\n", sum);
    printf("평균은 %.2f입니다.\n", av);
    printf("최대값은 %d입니다.\n", max);
    printf("최소값은 %d입니다.\n", min);

    return 0;
}
