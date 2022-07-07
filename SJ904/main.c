#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *inf;
   char ch;
   if((inf = fopen( "..\\sejong.txt", "rt")) == NULL)
    {
        printf("입력할  file에 문제 발생 !! \n");
        exit(0);
    }
    printf("\n File 내용을 처음부터 끝까지 출력\n");
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }

    rewind(inf);

    printf("\n File 내용을 처음부터 끝까지 출력\n");
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }

     fseek(inf, 2L, SEEK_SET);
   // fseek(inf, 2L, SEEK_CUR);
   // fseek(inf, -3L, SEEK_END);

    printf("\n File 내용을 %d번째 Byte 부터 다시 출력\n", ftell(inf) );
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }
    fclose(inf);

    return 0;
}
