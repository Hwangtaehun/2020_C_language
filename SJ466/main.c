#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, num3, tot;
    num1 = 1;
    num2, tot = 0;
    num3 = 0;

    while( num3 <= 21 )
    {
        num3 = num1 + num2;
        tot += num3;
        num1 = num2;
        num2 = num3;
    }

    printf("°á°ú = %d\n", tot);
    return 0;
}
