#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    printf("main�� �μ� ������ %d�� �Դϴ�.\n", argc);
    for(i = 0;i < argc; i++)
    {
        printf("%d��° �μ��� %s�Դϴ�.\n", i, argv[i]);
    }
    return 0;
}
