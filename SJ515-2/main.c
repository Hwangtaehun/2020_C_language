#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, weight;

    while(1)
    {
        printf("2������ ��ȯ�� 10�� ������ �Է��ϼ���. (����� 0) ==> ");
        scanf("%d", &num);
        if(num == 0)
            break;
        weight = 2;
        while(weight <= num)
        {
            weight *= 2;
        }
        weight /= 2;
        printf("\n 10 ���� %7d�� 2 ������ --->", num);
        while(weight != 0)
        {
           printf("%2d", num/weight);
           num %= weight;
           weight /= 2;
        }
        printf("\n\n");
    }
    return 0;
}
