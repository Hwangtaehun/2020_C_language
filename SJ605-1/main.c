#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int arr[MAX];
    int i, sum, max, min;
    float av;
    int *pt;

    pt = arr;
    printf("정수를 %d 개 입력하세요. \n", MAX);
    for(i =0; i<MAX;i++)
    {
        scanf("%d", arr+i);
    }

    printf("배열에 입력된 내용 출력 \n");
    for(i=0;i<MAX;i++){
        printf("%5d", pt[i]);
    }
    putchar("\n");

    sum = 0;
    for(pt = arr ; pt < arr+MAX; pt++){
        sum += *pt;
    }
    av = (float)sum / (float)MAX;

    max = min = *arr;
    for(pt = arr ; pt < arr+MAX; pt++){
        if(*pt > max)
            max = *pt;
        if(*pt < min)
            min = *pt;
    }

    printf("합은 %d  입니다.\n", sum);
    printf("평균은 %.2f 입니다.\n", av);
    printf("최대값은 %d 입니다.\n", max);
    printf("최소값은 %d 입니다.\n", min);
    return 0;
}
