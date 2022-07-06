#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    FILE *inf, *outf;
    char ch;
    if(argc < 3)
        printf("인수의 수가 틀려유 !! \n"), exit(0);

    if((inf = fopen(argv[1], "rt")) == NULL)
        printf("원본 File에 문제가 생겼네유 !!\n"), exit(0);

    if((outf = fopen(argv[2], "wt")) == NULL)
        printf("복사본 File에 문제가 생겼네유 !!\n"), exit(0);

    while((ch = getc(inf)) != EOF)
    {
        putc(ch, outf);
    }
    printf("%s File 을 %s File 로 복사 \n", argv[1], argv[2]);
    fclose(inf);
    fclose(outf);
    return 0;
}
