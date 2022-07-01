#include <stdio.h>

void ArrayPrn(int pt[], int cnt);
void SelSort(int pt[], int cnt);
void Swap(int &num1, int  &num2);

#define MAX 10

int main() {
	int arr[MAX] = { 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };

	printf(" sort 전의 배열 내용 : \t");
	ArrayPrn(arr, MAX);
	SelSort(arr, MAX);

	printf("\n sort 후의 배열 내용 : \t");
	ArrayPrn(arr, MAX);

	return 0;
}

void ArrayPrn(int pt[], int cnt)
{
    int i;
    for (i = 0; i < cnt; i++)
	{
		printf("%3d", pt[i]);
	}
	printf("\n\n");
}

void SelSort(int pt[], int cnt)
{
    int i, j;
    for (i = 0; i < MAX - 1; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (pt[i] > pt[j])
			{
				Swap(pt[i], pt[j]);
			}
		}
	}
}

void Swap(int &num1, int  &num2)
{
    int temp;
    temp = num1;
    num1 = num2;
    num2 = temp;
}
