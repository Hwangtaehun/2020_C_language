#include <stdio.h>
#include <stdlib.h>

int main()
{
    char ch;
    int cnt = 0;
    printf("문자를 입력 종료하려면 '*'를 입력\n");
    while( ch = getchar(), ch != -1){
        putchar(ch);
        cnt++;
    }
    printf(" 입력된 문자수 = %d \n", cnt);
    return 0;
}
