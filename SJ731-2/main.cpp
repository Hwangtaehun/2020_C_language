#include<stdio.h>

void Func1(int (&num)[5]);
void ArrayPrn(int (&num)[5]);
int ArrayTotal(int (&arr)[5]);

int main(void){
    int arr[5] = {11, 22, 33, 44, 55};
    int sum;

    printf("�Լ����� �迭 ���� �� ����\n");
    ArrayPrn(arr);
    Func1(arr);
    printf("�Լ����� �迭 ���� �� ����\n");
    ArrayPrn(arr);
    sum = ArrayTotal(arr);
    printf("�迭 ���� �� = %d\n", sum);
    return 0;
}

void Func1(int (&num)[5])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        num[i] += 100;
    }
}

void ArrayPrn(int (&num)[5])
{
    int i;
    printf("�迭�� ũ��� %d Byte �Դϴ�.\n", sizeof(num));
    for(i = 0; i < 5; i++)
    {
       printf("%5d", num[i]);
    }
    printf("\n");
}

int ArrayTotal(int (&arr)[5])
{
    int i, tot = 0;
    for(i = 0; i< sizeof(arr) / sizeof(int); i++)
    {
        tot += arr[i];
    }
    return tot;
}
