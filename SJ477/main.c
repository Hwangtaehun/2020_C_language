#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n , min = 999, max = 0, cnt = 0, tot = 0;
    double av;

    printf("���� �Է�, �����Ϸ��� ^Z�� �Է��ϼ���. \n");
    while(scanf("%d", &n) != EOF)
     {
        if( n > max )
        {
            max = n;
        }
        if( n < min )
        {
            min = n;
        }
        tot += n;
        cnt++;
    }

    av = (double)tot / (double)cnt;
    printf("\n�Էµ� %d �� �ڷ��� �ּҰ� = %d\n", cnt, min);
    printf("�Էµ� %d �� �ڷ��� �ִ밪 = %d\n", cnt, max);
    printf("�Էµ� %d �� �ڷ��� �հ� = %d\n", cnt, tot);
    printf("�Էµ� %d �� �ڷ��� ��� = %.2f\n", cnt, av);
    return 0;
}
