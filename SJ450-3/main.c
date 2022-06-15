#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a =0, b =0, s=1;
    for(a = 1; a<=100; a++){
        b += a * s;
        s = -s;
    }
   printf("°á°ú = %d\n", b);
    return 0;
}
