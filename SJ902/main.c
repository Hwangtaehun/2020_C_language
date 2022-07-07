#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *inf;
    char ch;
    if((inf = fopen( "..\\sejong.txt", "rt")) == NULL)
    {
        printf("file open이 이상 해 유 !! \n");
        exit(0);
    }

    while((ch = getc(inf)) != EOF)
    {
        putc(ch, stdout);
    }
    fclose(inf);
    return 0;
}
