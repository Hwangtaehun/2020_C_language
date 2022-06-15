#include <stdio.h>
#include <stdlib.h>

int main()
{
    int cnt =0;
    char ch;
    for(ch = 'A'; ch <= 'Z'; ch++){
        putchar(ch);

        if(++cnt %4 == 0){
            putchar('\n');
        }
    }
    putchar('\n');
    return 0;
}
