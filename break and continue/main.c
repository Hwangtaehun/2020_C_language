#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a;

    for(a=1; a <= 5; a++){
        printf("aaa\t");
        if(a == 2){
            continue;
        }
        printf("bbb\n");
    }

    return 0;
}
