#include <stdio.h>
#include <stdlib.h>

int main()
{
    char st[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp;
    int i, j;

    for(i =0; i<4;i++){
        printf("%s\n", st);
        for(j = 0; j<13;j++){
            temp = st[j];
            st[j] = st[25-j];
            st[25-j] = temp;
        }
    }
    return 0;
}
