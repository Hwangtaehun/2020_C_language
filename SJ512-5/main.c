#include <stdio.h>
#include <stdlib.h>
#define LIMIT 500

int main()
{
    int i, j, num, array[LIMIT] = {0}, cnt=0;
    printf("소수를 얼마까지 구할 건지 입력해주세요. : ");
    scanf("%d", &num);
    for(i = 2; i <= num ; i ++)
    {
        array[i] = i;
    }
    for(i = 2; i <= 100 ; i++)
    {
        if(array[i] != 0){
            for(j = i + i; j <= num; j += i)
            {
                array[j] = 0;
            }
        }
    }
    printf("\n ***** %d 까지의 소수 *****\n", num);
    for(i=2; i <= num; i++)
    {
        if(array[i] != 0)
        {
            printf("%5d", array[i]);
            cnt++;
            if(cnt % 5 == 0)
                putchar('\n');
        }
    }
    printf("\n소수의 수는 %d개 입니다.\n", cnt);
    return 0;
}
