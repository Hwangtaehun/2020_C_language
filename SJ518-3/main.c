#include <stdio.h>
#define MAX 10

int main() {
	int arr[MAX] = { 1, 2, 3, 4, 6, 5, 7, 8, 9, 10 };
	int i, j, temp, pa, pb, cnt = 0;

	printf(" sort 전의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n\n");

	pa = MAX - 1;
	for (i = 0; i < MAX - 1; i++)
	{
		pb = pa;
		pa = 0;

		for (j = 0; j < pb ; j++)
		{
			cnt++;
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
				pa = j;
			}
		}
		if (pa == 0)
			break;
	}

	printf("\n sort 후의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n안쪽 Loop 반복횟수 = %d\n", cnt);

	return 0;
}
