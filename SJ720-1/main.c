#include <stdio.h>
#include <stdlib.h>

int Gcm(int a, int b);

int main()
{
    int a, b, lcm, gcm;
    while( 1 )
    {
        printf("���� 2 �� �Է� :");
        scanf("%d%d", &a, &b);

        if( a*b == 0 )
            break;

        gcm =Gcm(a, b);
        lcm = a * b / gcm;

        printf("�ִ����� = %d, �ּҰ���� = %d \n", gcm, lcm);
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
