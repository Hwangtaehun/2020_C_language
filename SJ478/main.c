#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, kun, jak, na, lcm, gcm;
    while( 1 )
    {
        printf("���� 2 �� �Է� :");
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

        printf("�ִ����� = %d, �ּҰ���� = %d \n", gcm, lcm);
    }
    return 0;
}
