#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c, d, e;

    printf("���� 3�� �Է� : ");
    scanf("%d %d %d", &a, &b, &c);

    e = ( (d = (a>b)?a:b ) > c) ? d : c;

    printf("ū�� = %d\n", e);
    printf("������ = %d\n", ( (d = (a>b)?a:b ) < c) ? d : c);

    return 0;
}
