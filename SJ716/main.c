#include <stdio.h>
#include <stdlib.h>

int plus(int n, int m);

int main()
{
    int a = 3, b = 5, c;
    c = plus(a, b);
    printf("�� = %d\n", c);

    return 0;
}

int plus(int n, int m){
    int temp;
    temp = n + m;

    return temp;

    printf("return �� ���������� ??? \n");
}
