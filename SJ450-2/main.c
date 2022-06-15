#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a= 0, b=0, sw =0;
    for(a = a; a <= 100 ; a++ ){
        if( sw == 0 ){
            b += a;
            sw = 1;
        }
        else{
            b -= a;
            sw = 0;
        }
    }

    printf("°á°ú = %d\n", b);
    return 0;
}
