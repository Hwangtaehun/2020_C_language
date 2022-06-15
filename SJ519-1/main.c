#include <stdio.h>
#define MAX 10

int main() {
	int arr[MAX] = { 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };
	int i, j, temp;

	printf(" sort 전의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n\n");

	for (i = 0; i < MAX - 1; i++)
	{
		for (j = i + 1; j < MAX; j++)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	printf("\n sort 후의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	putchar('\n');

	return 0;
}
