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
    printf("�հ��� ��: %d \n", cnt);
    printf("�հ��� ����: %d \n", tot);
    printf("�հ��� ���: %.2f \n", av);
    return 0;
}
