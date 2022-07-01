#include <stdio.h>
#define MAX 10

void ArrayPrn(int (&rep)[MAX], int cnt);
void InsertSort(int (&rep)[MAX], int cnt);

int main() {
	int arr[MAX] = { 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };

	printf(" sort 전의 배열 내용 : \t");
	ArrayPrn(arr, MAX);
	InsertSort(arr, MAX);

	printf("\n sort 후의 배열 내용 : \t");
	ArrayPrn(arr, MAX);
	return 0;
}

void InsertSort(int (&rep)[MAX], int cnt)
{
    int i, j, key;

    for (i = 1; i < cnt; i++)
	{
		key = rep[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (key > rep[j])
				break;
			rep[j + 1] = rep[j];
		}
		rep[j + 1] = key;
	}
}

void ArrayPrn(int (&rep)[MAX], int cnt)
{
    int i;

    for (i = 0; i < cnt; i++)
	{
		printf("%3d", rep[i]);
	}
	printf("\n");
}
