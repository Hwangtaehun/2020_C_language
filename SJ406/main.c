#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    scanf("%d", &n);
    if(n>0)
        printf("입력된 수는 양수입니다.\n");
    else if(n==0)
        printf("입력된 수는 영입니다.\n");
    else
        printf("입력된 수는 음수 입니다.\n");
    return 0;
}
