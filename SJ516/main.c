#include <stdio.h>
#include <stdlib.h>

int main()
{
    char num[100] = "";
    int i, j, cnt, dec, jinsu;
    while(1)
        {
        printf("��ȯ�� ���� ������ �Է��ϼ���. (���� ^Z) ==> ");
        if(scanf("%s%d", num, &jinsu) == EOF)
            break;
        if(jinsu < 2 || jinsu > 16)
        {
           printf("������ ������ 2-16 �����Դϴ�. !!!\n");
           continue;
        }
        cnt = 0;
        while(num[cnt] != '\0')
        {
            cnt++;
        }
        j = 1;
        dec = 0;
        for(i = cnt - 1; i >= 0; i--){
            if(num[i] >= '0' && num[i] <= '9')
            {
                dec += (num[i] - '0') * j;
            }
            else
            {
                dec += (num[i]-'A'+10) * j;
            }
            j *= jinsu;
        }
        printf("\n %d ���� %7s�� 10 ������ ---> %7d \n\n", jinsu, num, dec);
    }
    return 0;
}
