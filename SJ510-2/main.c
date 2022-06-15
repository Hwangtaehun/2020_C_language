#include <stdio.h>
#include <stdlib.h>

int main()
{
   char st[27] = "";
    int i;
    for(i = 0; i < 26 ; i++){
        st[i] = 'A' + i;
        printf("%s\n", st);
    }
    return 0;
}
