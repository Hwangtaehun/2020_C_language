#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, min = 999, max = 0, cnt =0;
    printf("������ �Է�, �����Ϸ��� 999�� �Է��ϼ���.\n" );
    while(scanf("%d", &n), n != 999)
    {
        cnt++;
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
    }
    printf("�Էµ� %d �� �ڷ��� �ּ� �� = %d\n", cnt, min);
    printf("�Էµ� %d �� �ڷ��� �ִ� �� = %d\n", cnt, max);
    return 0;
}
