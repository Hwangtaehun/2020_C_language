#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i, j;
    printf("2 �����迭 �� ����� ���� \n");
    for(i=0;i<4;i++)
    {
        for(j=0; j<3; j++)
        {
            printf("arr[%d][%d]�� �� = %2d, ���� = %u \n", i, j, arr[i][j], &arr[i][j]);
        }
    }
    printf("arr = %u, arr + 1 = %u", arr, arr+1);
    return 0;
}
