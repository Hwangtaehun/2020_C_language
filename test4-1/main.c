#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;

    c = getchar();

    if( c == 'A' )
    {
        printf("A입니다.");
    }
    else
    {
        printf("A가 아닙니다.");
    }
    return 0;
}
