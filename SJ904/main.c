#include <stdio.h>
#include <stdlib.h>

int main()
{
   FILE *inf;
   char ch;
   if((inf = fopen( "..\\sejong.txt", "rt")) == NULL)
    {
        printf("�Է���  file�� ���� �߻� !! \n");
        exit(0);
    }
    printf("\n File ������ ó������ ������ ���\n");
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }

    rewind(inf);

    printf("\n File ������ ó������ ������ ���\n");
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }

     fseek(inf, 2L, SEEK_SET);
   // fseek(inf, 2L, SEEK_CUR);
   // fseek(inf, -3L, SEEK_END);

    printf("\n File ������ %d��° Byte ���� �ٽ� ���\n", ftell(inf) );
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }
    fclose(inf);

    return 0;
}
