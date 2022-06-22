#include <stdio.h>
#include <stdlib.h>

int Plus_a(int num1, int num2);
void Plus_b(int num1, int num2, int *pt);

int main()
{
    int a = 55, b= 33, c, d;
    c = Plus_a(a, b);
    printf(" c = %d \n", c);
    Plus_b(a, b, &d);
    printf("&d = %u, d = %d\n", &d, d);
    return 0;
}

int Plus_a(int num1, int num2){
    int temp;
    temp = num1 + num2;
    return temp;
}

void Plus_b(int num1, int num2, int *pt){
    *pt = num1 + num2;
    printf("pt = %u\n", pt);
}
