#include <stdio.h>
#include <stdlib.h>
#define COUNT 5

int main()
{
    int i, n, min = 999, max = 0;
    printf("������ %d�� �Է��ϼ���.\n", COUNT);
    for(i = 0; i <COUNT;i++)
    {
        scanf("%d", &n);
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
    }
    printf("�Էµ� %d �� �ڷ��� �ּ� �� = %d\n", COUNT, min);
    printf("�Էµ� %d �� �ڷ��� �ִ� �� = %d\n", COUNT, max);
    return 0;
}
