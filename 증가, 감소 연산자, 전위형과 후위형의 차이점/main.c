#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a1, a2, b1, b2;
    a1 = b1 =3;
    a2 = ++a1;

    b2 = b1++;
    printf(a1 = %d, a2 = %d\n, a1, a2);
    printf(b1 = %d, b2 = %d\n, b1, b2);
    return 0;
}
