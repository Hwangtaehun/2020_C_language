#include <stdio.h>
#include <stdlib.h>

void ReverseString(char str[]);
void ShiftString(char *str);

int main()
{
    char st[27] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char temp;
    int i;

    printf("문자열 뒤집기\n");
    for(i =0; i<4;i++){
        printf("%s\n", st);
        ReverseString(st);
    }

    printf("문자열 이동\n");
     for(i =0; i<4;i++){
        printf("%s\n", st);
        ShiftString(st);
    }
    return 0;
}

void ReverseString(char str[])
{
    int j;
    char temp;
    for(j = 0; j<13;j++)
    {
        temp = str[j];
        str[j] = str[25-j];
        str[25-j] = temp;
    }
}

void ShiftString(char *str)
{
    char temp;
    temp = *str;
    while(*str != NULL)
    {
        *str = *(str+1);
        str++;
    }
    *(str - 1) = temp;
}
