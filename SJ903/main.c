#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *outf, *inf;
    char ch;
    if((outf = fopen( "sejong2.txt", "at")) == NULL)
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
    printf("\n File ������ �ٽ� ����� ���ô�\n");
    if((inf = fopen("sejong2.txt", "rt")) == NULL)
    {
        printf("�Է� �� file�� ���� �߻� !! \n");
        exit(0);
    }
    while((ch=getc(inf)) != EOF )
    {
        putc(ch, stdout);
    }
    fclose(inf);

    return 0;
}
