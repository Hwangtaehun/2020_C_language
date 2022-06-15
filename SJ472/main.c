#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, tot = 0, cnt;
    double av;
    printf(" 자료의 갯수 : ");
    scanf("%d", &cnt);
    printf("정수를 %d 개 입력하세요.\n", cnt);
    for(i = 0;i < cnt; i++){
        scanf("%d", &n);
        tot =+ n;
    }
    av = (double)tot / (double)cnt;
    printf("입력된 %d 개 자료의 함계 = %d\n", cnt, tot);
    printf("입력된 %d 개 자료의 평균 = %.2f\n", cnt, av);
    return 0;
}
