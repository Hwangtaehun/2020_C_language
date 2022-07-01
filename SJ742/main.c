#include <stdio.h>
#include <stdlib.h>
int sq(int n);
#define SQ1(n) n*n
#define SQ2(n) ((n) * (n))

int main(int argc, char **argv)
{
    int a, b;
    a = sq(2);
    b = sq(2+2);
    printf("sq   함수  실행 후의 a = %d, b = %d \n", a, b);

    a = SQ1(2);
    b = SQ1(2 + 2);
    printf("SQ1 macro 처리 후의 a = %d, b = %d \n", a, b);

    a = SQ2(2);
    b = SQ2(2 + 2);
    printf("SQ2 macro 처리 후의 a = %d, b = %d \n", a, b);
    return 0;
}

int sq(int n)
{
    return (n * n);
}
