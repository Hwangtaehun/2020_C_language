#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    printf("시헙점수를 입력해주세요.\n");
    scanf("%d", &a);

    if(a>= 60)
    {
        printf("합격");
    }
    else
    {
        printf("불합격");
    }
    return 0;
}
