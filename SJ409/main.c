#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a, b, c;
    printf("���� 2�� �Է� : ");
    scanf("%d %d", &a, &b);
    if(a>b)
        c = a;
    else
        c = b;

    printf("ū �� = %d\n", c);

    printf("���� ��  = %d\n", (a<b) ? a : b);
    return 0;
}
