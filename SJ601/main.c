#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100, b = 200;
    int *pt;
    printf("a�� ������ %u, %p, %X �Դϴ�. \n", &a, &a, &a);
    printf("b�� ������ %u �Դϴ�. \n", &b);
    printf("pt�� ������ %u �Դϴ�. \n", &pt);

    pt = &a;
    printf("pt = %u \n", pt);
    printf("*pt = %d \n", *pt);
    pt = &b;
    printf("pt = %u \n", pt);
    printf("*pt = %d \n", *pt);
    *pt = *pt + 5;
    printf("*pt = %d, b = %d\n", *pt, b);
    return 0;
}
