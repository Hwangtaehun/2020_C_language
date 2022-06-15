#include <stdio.h>
#include <stdlib.h>

int main()
{
    char st[30];
    int a, b, c;

    scanf("%s %d-%d-%d", st, &a, &b, &c);
    printf("이름은 %s입니다.\n생일은 %d년 %d월 %d일 입니다.\n", st, a, b, c);

    return 0;
}

