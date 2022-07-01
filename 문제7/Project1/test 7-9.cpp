#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void ArrayPrn(int pt[], int cnt);
void SelSort(int pt[], int cnt, int select);
void Swap(int& num1, int& num2);

#define MAX 10

void main(void)
{
	int arr[MAX] = { 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };
	printf("sort 전의 배열 내용 : \t");
	ArrayPrn(arr, MAX);
	SelSort(arr, MAX, 0);
	printf("\n 오름차순 sort 후의 배열 내용 : ");
	ArrayPrn(arr, MAX);
	SelSort(arr, MAX, 1);
	printf("\n 내림차순 sort 후의 배열 내용 : ");
	ArrayPrn(arr, MAX);
}

void ArrayPrn(int pt[], int cnt)
{
	int i;
	for ( i = 0; i < cnt; i++)
	{
		printf("%3d", pt[i]);
	}
	printf("\n");
}

void SelSort(int pt[], int cnt, int select)
{
	int i, j;
	for (i = 0; i < cnt - 1; i++)
	{
		for ( j = i + 1; j < cnt; j++)
		{
			if (select == 0)
			{
				if (pt[i] > pt[j])
					Swap(pt[i], pt[j]);
			}
			else
			{
				if(pt[i] < pt[j])
					Swap(pt[i], pt[j]);
			}
		}
	}
}

void Swap(int& num1, int& num2)
{
	int temp;
	temp = num1;
	num1 = num2;
	num2 = temp;
}