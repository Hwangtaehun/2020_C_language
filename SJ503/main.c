#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int k[MAX];
    int i, sum, max, min;
    float av;
    printf(" ������ %d �� �Է��ϼ���. \n", MAX);
    for( i = 0 ; i < MAX; i++)
    {
        scanf("%d", &k[i] );
    }
    printf(" �迭�� �Էµ� ���� ��� \n", MAX);
    for( i = 0 ; i < MAX; i++)
    {
        printf("%5d", k[i]);
    }
     for( i = 0, sum = 0 ; i < MAX; i++)
    {
        sum += k[i];
    }
    av = (float)sum / (float)MAX;

    max = min = k[0];
    for( i = 1 ; i < MAX; i++)
    {
        if(k[i] > max)
            max = k[i];
        if(k[i] < min)
            min = k[i];
    }
    printf("���� %d�Դϴ�.\n", sum);
    printf("����� %.2f�Դϴ�.\n", av);
    printf("�ִ밪�� %d�Դϴ�.\n", max);
    printf("�ּҰ��� %d�Դϴ�.\n", min);

    return 0;
}
