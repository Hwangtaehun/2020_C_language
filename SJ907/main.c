#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *inf;
    char ch;
    if(argc < 2)
        printf("보여출 file명이 없어요!! \n"), exit(0);
    if((inf = fopen(argv[1], "rt")) ==  NULL)
        printf("보여출 File에 문제가 생겼네요!! \n"), exit(0);
    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }
    printf("aaa\n");
    fclose(inf);
    return 0;
}
