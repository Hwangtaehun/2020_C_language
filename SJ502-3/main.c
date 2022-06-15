#include <stdio.h>
#include <stdlib.h>
#define ARRAY_CUT 10

int main()
{
    int score[ARRAY_CUT] = { 88, 67, 78, 98, 89, 79, 88, 83, 73, 99};
    int i, min, min_gap=99, gap;

    for(i = 0; i < ARRAY_CUT; i++){
        gap = (score[i] > 80) ? score[i]-80 : 80 - score[i];
        if(min_gap > gap){
            min_gap = gap;
            min = score[i];
        }
    }

    printf("80에 가장 가까운 수 = %d \n", min);
    return 0;
}
