#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =0, b=0;
    for(a=1; a<=100; a++)
    {
        if(a % 2 == 0)
        {
            b -= a;
        }
        else
        {
            b += a;
        }
    }
    printf("��� = %d\n", b);
    return 0;
}
