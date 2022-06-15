#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int arr1[5] = {11, 12, 13, 14, 15};
    int arr2[5] = {21, 22, 23, 24, 25};
    int *pt[4];
    int i, j;

    pt[0] = arr1;
    pt[1] = arr2;
    pt[2] = arr[0];
    pt[3] = arr[2];

    printf("pointer배열에 대입한 후의 내용\n");
    for(i = 0; i < 4; i++){
        for(j = 0; j < 5; j++){
            printf("pt[%d][%d] = %2d\n", i, j, pt[i][j]);
        }
    }

    printf("arr1 = %u \tarr2 = %u \n", arr1, arr2);
    printf("arr  = %u \tarr+1 = %u \n", arr, arr + 1);
    printf("arr+2 = %u \tarr+3 = %u \n", arr + 2, arr + 3);

    return 0;
}
