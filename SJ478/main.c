#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, kun, jak, na, lcm, gcm;
    while( 1 )
    {
        printf("정수 2 개 입력 :");
        scanf("%d%d", &a, &b);

        if( a*b == 0 )
            break;

        if(a>b)
            kun=a, jak=b;
        else
            kun=b, jak=a;

        while(na = kun % jak, na != 0)
        {
            kun = jak;
            jak = kun;
        }
        gcm = jak;
        lcm = a * b / gcm;

        printf("최대공약수 = %d, 최소공배수 = %d \n", gcm, lcm);
    }
    return 0;
}
