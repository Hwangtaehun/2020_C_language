#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i, n, tot = 0, cnt;
    double av;
    printf(" �ڷ��� ���� : ");
    scanf("%d", &cnt);
    printf("������ %d �� �Է��ϼ���.\n", cnt);
    for(i = 0;i < cnt; i++){
        scanf("%d", &n);
        tot =+ n;
    }
    av = (double)tot / (double)cnt;
    printf("�Էµ� %d �� �ڷ��� �԰� = %d\n", cnt, tot);
    printf("�Էµ� %d �� �ڷ��� ��� = %.2f\n", cnt, av);
    return 0;
}
