#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ( ( (x) > (y) ) ? (x) : (y) )
#define MIN(x, y) ( ( (x) < (y) ) ? (x) : (y) )
#define SWAP(x, y)  (x) ^= (y); (y) ^= (x); (x) ^= (y);

int main(int argc, char **argv)
{
    int a = 3, b = 5;
    printf("ū  �� = %d\n", MAX(a, b));
    printf("������ = %d\n", MIN(a, b));
    SWAP(a, b);
    printf("��ȯ �� a = %d, b = %d \n", a, b);
    return 0;
}
