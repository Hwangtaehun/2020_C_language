#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int (*pt1)[2];
    int (*pt2)[4];
    int i;
    pt1 = ( int (*)[2] )arr;
    pt2 = ( int (*)[4] )arr;

    printf("arr = %u, arr + 1 = %u \n", arr, arr + 1);
    printf("pt1 + 1 = %u, pt2 + 1 = %u, \n", pt1 + 1, pt2 + 1);

    for(i = 0; i < 3; i++){
        printf("pt1[%d][0] = %2d, pt1[%d][1] = %2d \t", i, pt1[i][0], i, pt1[i][1]);
        printf("pt2[%d][0] = %2d, pt2[%d][1] = %2d \n", i, pt2[i][0], i, pt2[i][1]);
    }
    return 0;
}
