#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    printf("문자 1개 입력 \n");
    ch = getche();
    printf("문장 %c에 대한 코드는 %d입니댜. \n", ch, ch);
    putchar('A');
    putchar('\n');
    putchar(0x042);
    return 0;
}
