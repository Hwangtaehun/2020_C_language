#include <stdio.h>
#include <stdlib.h>

int main()
{
    int count[26] = {0};
    char temp;
    int i;
    printf("�빮�ڸ� �Է��ϼ���. ����� ^Z\n");
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
            printf("%c�� �Էµ� Ƚ���� %d���Դϴ�.\n", 'A'+i, count[i]);
        }
    }
    return 0;
}
