#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    int i;
    printf("main의 인수 갯수는 %d개 입니다.\n", argc);
    for(i = 0;i < argc; i++)
    {
        printf("%d번째 인수는 %s입니다.\n", i, argv[i]);
    }
    return 0;
}
