#include <stdio.h>
#include <stdlib.h>

void PlusMinus(int num1, int num2, int *pt1, int *pt2);

int main()
{
    int a = 55, b = 33, c, d;
    PlusMinus(a, b, &c, &d);
    printf("c = %d, d = %d\n", c, d);
    return 0;
}

void PlusMinus(int num1, int num2, int *pt1, int *pt2){
    *pt1 = num1 + num2;
    *pt2 = num1 - num2;
}
