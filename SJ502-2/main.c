#include <stdio.h>
#include <stdlib.h>
#define ARRAY_CUT 10
int main()
{
    int score[ARRAY_CUT] = { 88, 67, 78, 98, 89, 79, 88, 83, 73, 99};
    int i, cnt = 0, tot = 0;
    float av;
    for(i = 0; i < ARRAY_CUT; i++){
        if( score[i] >= 80){
            cnt++;
            tot += score[i];
            printf("%5d", score[i]);
        }
    }
    printf("\n");
    av = (float)tot / (float)cnt;
    printf("합격자 수: %d \n", cnt);
    printf("합격자 총점: %d \n", tot);
    printf("합격자 평균: %.2f \n", av);
    return 0;
}
