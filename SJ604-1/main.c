#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int i, *pt;
    pt = arr;
    printf("배열의 번지와 pointer 연산 \n");
    for(i=0 ; i<5;i++){
        printf("&arr[%d] = %u, arr + %d = %u \n", i, &arr[i], i, arr+i);
    }
    printf("\n배열의 값와 pointer 연산 값 \n");
    for(i=0 ; i<5;i++){
        printf("arr[%d] = %d, *(arr + %d) = %d \n", i, arr[i], i, *(arr+i));
    }
    printf("\npointer변수를 사용한 경우 \n");
    for(i=0 ; i<5;i++){
        printf("&pt[%d] = %u, pt + %d = %u \n", i, &pt[i], i, pt+i);
    }
     for(i=0 ; i<5;i++){
        printf("pt[%d] = %d, *(pt + %d) = %d \n", i, pt[i], i, *(pt+i));
    }
    return 0;
}
