#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n = 0, cnt = 0;
    printf("���� �Է�, �����Ϸ��� ^Z�� �Է��ϼ���. \n ");
    while(scanf("%d", &n) != EOF)
    {
        cnt++;
        printf("%d�� %d��° �Էµ� �� �Դϴ�.", n, cnt);
    }
    printf("��ü %d �� �Է� �ϼ̽��ϴ�.\n", cnt);
    return 0;
}
