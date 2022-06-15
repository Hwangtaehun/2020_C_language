#include <stdio.h>
#include <stdlib.h>

int main()
{
    char st[27];
    int i, j;
    for(i = 0; i < 26 ; i++){
        st[i] = 'A' + i;
    }
    for(i =0; i<26;i++){
        for(j = 0; j<26;j++){
            putchar(st[j]);
        }
        putchar('\n');
    }
    return 0;
}
