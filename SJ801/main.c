#include <stdio.h>
#include <stdlib.h>

typedef unsigned char BYTE;
typedef unsigned int UINT;

typedef int ARRAY[10];
typedef int* PINT;

typedef long LONG;
typedef long LPARAM;
typedef long COLORREF;

int main(int argc, char **argv)
{
    BYTE ch = 'a', str[10] = "abcd";
    UINT a = 100, b = 200;
    ARRAY k = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    LONG ll = 1234L;
    PINT pa, pb, pc;

    printf("ch = %c, str = %s \n", ch, str);
    printf("a = %d, b = %d \n", a, b);

    for(a = 0 ; a < 10; a++)
    {
        printf("%5d", k[a]);
    }
    printf("\n");

    pa = k;
    pb = k + 1;
    pc = k + 2;

    printf("*pa = %5d\n", *pa);
    printf("*pb = %5d\n", *pb);
    printf("*pc = %5d\n", *pc);

    return 0;
}
