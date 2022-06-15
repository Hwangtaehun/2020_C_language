#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i, *pt;
    pt = (int *)arr;
    printf("arr = %u, arr + 1 = %u, pt + 1 = %u \n", arr, arr + 1, pt + 1);
    for(i = 0; i < 12; i++)
    {
        printf("pt + %2d = %u, *(pt + %2d) = %2d , " , i, (pt + i), i, *(pt + i));
        printf("pt[%2d] = %d\n", i, pt[i]);
    }
    return 0;
}
