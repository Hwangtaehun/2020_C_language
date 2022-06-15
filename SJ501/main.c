#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i;
    int k[5], m[5];
    k[0] = 1;
    k[1] = 2;
    k[2] = 3;
    k[3] = 4;
    k[4] = 5;
    for( i = 0 ;  i < 5 ; i++)
    {
        m[i] = i + 1;
    }
    for(i = 0; i < 5 ; i++)
    {
        printf("k[%d] \ %d \t m[%d] = %d \n", i ,k[i], i, m[i]);
    }
    printf("int 형의 크기는 %d Byte 입니다. \n", sizeof(int));
    printf("배열 k의 크기는 %d Byte 입니다.\n", sizeof(k));
    printf("k 배열 요소의 수는 %d 개 입니다.\n", sizeof(k)/sizeof(int));
    return 0;
}
