#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("���� 1�� �Է� \n");
    ch = getche();
    printf("���� %c�� ���� �ڵ�� %d�Դϴ�. \n", ch, ch);
    putchar('A');
    putchar('\n');
    putchar(0x042);
    return 0;
}
