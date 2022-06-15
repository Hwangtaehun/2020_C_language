#include <stdio.h>
#include <stdlib.h>

int main()
{
    char st[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp;
    int i, j;

    for(i =0; i<26;i++){
        printf("%s\n", st);
        temp = st[0];
        for(j = 0; j<25;j++){
            st[j] = st[j+1];
        }
        st[25]=temp;
    }
    return 0;
}
