#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count[26] = {0};
    char temp;
    int i;
    printf("대문자만 입력하세요. 종료는 ^Z\n");
    while((temp = getchar()) != EOF)
    {
        if(temp >= 'A' && temp <= 'Z'){
            count [ temp - 'A']++;
        }
    }
    //printf("\n");
    putchar('\n');
    for(i =0; i<26;i++)
    {
        if(count[i] != 0){
            printf("%c의 입력된 횟수는 %d번입니다.\n", 'A'+i, count[i]);
        }
    }
    return 0;
}
