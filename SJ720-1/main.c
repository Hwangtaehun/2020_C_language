#include <stdio.h>
#include <stdlib.h>

int Gcm(int a, int b);

int main()
{
    int a, b, lcm, gcm;
    while( 1 )
    {
        printf("정수 2 개 입력 :");
        scanf("%d%d", &a, &b);

        if( a*b == 0 )
            break;

        gcm =Gcm(a, b);
        lcm = a * b / gcm;

        printf("최대공약수 = %d, 최소공배수 = %d \n", gcm, lcm);
    }
    return 0;
}


int Gcm(int a, int b){
    int kun, jak, na;
    if(a>b)
        kun=a, jak=b;
    else
        kun=b, jak=a;

    while((na = kun % jak) != 0)
    {
        kun = jak;
        jak = na;
    }
    return jak;
}
