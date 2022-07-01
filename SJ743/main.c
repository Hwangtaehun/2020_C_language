#include <stdio.h>
#include <stdlib.h>
#define MAX(x, y) ( ( (x) > (y) ) ? (x) : (y) )
#define MIN(x, y) ( ( (x) < (y) ) ? (x) : (y) )
#define SWAP(x, y)  (x) ^= (y); (y) ^= (x); (x) ^= (y);

int main(int argc, char **argv)
{
    int a = 3, b = 5;
    printf("큰  수 = %d\n", MAX(a, b));
    printf("작은수 = %d\n", MIN(a, b));
    SWAP(a, b);
    printf("교환 후 a = %d, b = %d \n", a, b);
    return 0;
}
