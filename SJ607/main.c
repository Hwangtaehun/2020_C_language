#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[4][3] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int i;
    printf("arr = %u, arr[0] = %u, &arr[0][0] =  %u \n", arr, arr[0], &arr);
    printf("2차원 배열명의 1증가는 어떻게 될까요? \n");
    for(i = 0; i < 4; i++)
    {
        printf("arr + %d = %u, arr[%d] = %u\n", i, arr + i, i, arr[i]);
    }
    printf("행의 대표명으로 1 증가는 어떻게 될까요? \n");
    for(i = 0; i < 4; i++){
        printf("arr[0] + %d = %u, arr[1] + %d = %u\n", i, arr[0]+i, i, arr[1]+i );
    }
    printf("행의 대표명으로 값을 출력해봅시다. \n");
    for(i = 0; i < 4; i++)
    {
        printf("*(arr[0] + %d) = %d, *(arr[1] + %d) = %d\n", i, (*arr[0]+i), i, *(arr[1]+i) );
    }
    printf("2차원 배열명의 대표명으로 값을 출력해봅시다. \n");
    for(i = 0; i < 4; i++)
    {
        printf("*(arr + %d) = %u, **(arr + %d) = %d\n", i, *(arr + i), i, **(arr + i));
    }

    return 0;
}
