#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *inf;
    char ch;
    if(argc < 2)
        printf("������ file���� �����!! \n"), exit(0);
    if((inf = fopen(argv[1], "rt")) ==  NULL)
        printf("������ File�� ������ ����׿�!! \n"), exit(0);
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }
    printf("aaa\n");
    fclose(inf);
    return 0;
}
