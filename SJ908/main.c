#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *inf, *outf;
    char ch;
    if(argc < 3)
        printf("�μ��� ���� Ʋ���� !! \n"), exit(0);

    if((inf = fopen(argv[1], "rt")) == NULL)
        printf("���� File�� ������ ������� !!\n"), exit(0);

    if((outf = fopen(argv[2], "wt")) == NULL)
        printf("���纻 File�� ������ ������� !!\n"), exit(0);

    while((ch = getc(inf)) != EOF)
    {
        putc(ch, outf);
    }
    printf("%s File �� %s File �� ���� \n", argv[1], argv[2]);
    fclose(inf);
    fclose(outf);
    return 0;
}
