#include <stdio.h>
#include <stdlib.h>
#define MAX 5

int main()
{
    int arr[MAX];
    int i, sum, max, min;
    float av;
    int *pt;

    pt = arr;
    printf("������ %d �� �Է��ϼ���. \n", MAX);
    for(i =0; i<MAX;i++)
    {
        scanf("%d", arr+i);
    }

    printf("�迭�� �Էµ� ���� ��� \n");
    for(i=0;i<MAX;i++){
        printf("%5d", pt[i]);
    }
    putchar("\n");

    sum = 0;
    for(pt = arr ; pt < arr+MAX; pt++){
        sum += *pt;
    }
    av = (float)sum / (float)MAX;

    max = min = *arr;
    for(pt = arr ; pt < arr+MAX; pt++){
        if(*pt > max)
            max = *pt;
        if(*pt < min)
            min = *pt;
    }

    printf("���� %d  �Դϴ�.\n", sum);
    printf("����� %.2f �Դϴ�.\n", av);
    printf("�ִ밪�� %d �Դϴ�.\n", max);
    printf("�ּҰ��� %d �Դϴ�.\n", min);
    return 0;
}
