#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int cnt = 0;
    printf("���ڸ� �Է� �����Ϸ��� '*'�� �Է�\n");
    while( ch = getchar(), ch != -1){
        putchar(ch);
        cnt++;
    }
    printf(" �Էµ� ���ڼ� = %d \n", cnt);
    return 0;
}
