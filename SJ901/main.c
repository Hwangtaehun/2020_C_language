#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    FILE *outf;
    char ch;
    if((outf = fopen( "..\\sejong.txt", "ab")) == NULL)
    {
        printf("����� File�� ������ ������� !! \n");
        exit(0);
    }
    printf("���� �Է� ���� ctrl + z \n");
    while((ch = getc(stdin)) != EOF)
    {
        putc(ch, outf);
    }
    fclose(outf);
}
