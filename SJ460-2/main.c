#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, j, hap1 = 0, hap2;
    for(i = 2;  i <= 700; i++)
    {
        hap1 += (i-1);
        hap2 = 0;
        for(j = i + 1 ; hap1 > hap2 ; j++)
        {
            hap2 += j;
        }
        if(hap1 == hap2){
            printf("1 부터 %3d 의 중심 수 = %3d, 합 = %6d\n", j - 1, i, hap1);
        }
    }

    return 0;
}
