#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[5] = {10, 20, 30, 40, 50};
    int i, *pt;
    pt = arr;
    printf("pointer 변수 증가\n");
    for(i=0 ; i<5;i++)
    {
        printf("pt = %u, *pt = %d \n", pt, *pt);
        pt++;
    }
    printf("pointer 변수 감소\n");
    for(i=0 ; i<5;i++){
        pt--;
        printf("pt = %u, *pt = %d \n", pt, *pt);
    }
    printf("\n pt = &arr[2] 실행 후 \n");
    pt = &arr[2];
    printf("pt+1 = %u, pt[1] = %d\n", pt+1, pt[1]);
    printf("pt+2 = %u, pt[2] = %d\n", pt+2, pt[2]);
    return 0;
}
