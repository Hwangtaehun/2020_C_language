#include<stdio.h>

void Func1(int (&num)[5]);
void ArrayPrn(int (&num)[5]);
int ArrayTotal(int (&arr)[5]);

int main(void){
    int arr[5] = {11, 22, 33, 44, 55};
    int sum;

    printf("함수에서 배열 변경 전 내용\n");
    ArrayPrn(arr);
    Func1(arr);
    printf("함수에서 배열 변경 후 내용\n");
    ArrayPrn(arr);
    sum = ArrayTotal(arr);
    printf("배열 내용 합 = %d\n", sum);
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
    printf("배열의 크기는 %d Byte 입니다.\n", sizeof(num));
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
