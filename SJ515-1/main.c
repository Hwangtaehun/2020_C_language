#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, num1, n, i;
    char bin[32];
    while(1)
    {
        printf("2������ ��ȯ�� 10�� ������ �Է��ϼ���. (����� 0) ==> ");
        scanf("%d", &num);
        if(num == 0)
            break;
        n = 0;
        num1 = num;
        while( num != 0)
        {
            bin[n] = num % 2;
            num /= 2;
            n++;
        }
        printf("\n 10 ���� %7d�� 2 ������ --->", num1);
        for(i = n - 1; i >= 0; i--){
            printf("%2d", bin[i]);
        }
        printf("\n\n");
    }
    return 0;
}
