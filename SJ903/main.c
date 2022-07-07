#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *outf, *inf;
    char ch;
    if((outf = fopen( "sejong2.txt", "at")) == NULL)
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
    printf("\n File 내용을 다시 출력해 봅시다\n");
    if((inf = fopen("sejong2.txt", "rt")) == NULL)
    {
        printf("입력 할 file에 문제 발생 !! \n");
        exit(0);
    }
    while((ch=getc(inf)) != EOF )
    {
        putc(ch, stdout);
    }
    fclose(inf);

    return 0;
}
