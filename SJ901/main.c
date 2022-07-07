#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *outf;
    char ch;
    if((outf = fopen( "..\\sejong.txt", "ab")) == NULL)
    {
        printf("출력할 File에 문제가 생겼네유 !! \n");
        exit(0);
    }
    printf("문자 입력 종료 ctrl + z \n");
    while((ch = getc(stdin)) != EOF)
    {
        putc(ch, outf);
    }
    fclose(outf);
}
