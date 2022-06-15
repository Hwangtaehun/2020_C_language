#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100, b = 200;
    int *pt;
    printf("a의 번지는 %u, %p, %X 입니다. \n", &a, &a, &a);
    printf("b의 번지는 %u 입니다. \n", &b);
    printf("pt의 번지는 %u 입니다. \n", &pt);

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
