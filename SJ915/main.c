#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
    int hd, i, cnt, add;
    unsigned char buf[16];
    if(argc<2)
        printf("Çü½Ä error\n"), exit(0);
    if((hd = open(argv[1], O_RDONLY | O_BINARY)) == EOF)
        exit(0);
    add=0;
    while((cnt = read(hd, buf, 16)) != 0)
    {
        printf("%06X  ", 16*add++);
        for(i = 0; i < cnt; i++)
        {
            if(i == 8)
                printf(" ");
            printf("%02X ", buf[i]);
        }
        if(cnt < 16)
        {
            for(i = 0; i < 16- cnt ; i++)
                printf("  ");
        }
        printf(" | ");
        for(i = 0; i < cnt; i++)
        {
            if(buf[i] < ' ' || buf[i] > '~')
                putc('.', stdout);
            else
                putc(buf[i], stdout);
        }
        putc('\n', stdout);
    }
    close(hd);
    return 0;
}
