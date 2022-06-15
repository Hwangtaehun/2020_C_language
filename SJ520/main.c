#include <stdio.h>
#define MAX 10

int main() {
	int arr[MAX] = { 10, 8, 6, 4, 2, 9, 7, 5, 3, 1 };
	int i, j, key, cnt = 0;

	printf(" sort 전의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	printf("\n");

	for (i = 1; i < MAX; i++)
	{
		key = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (key > arr[j])
				break;
			arr[j + 1] = arr[j];
			cnt++;
		}
		arr[j + 1] = key;
	}

	printf("%3d번 교환\n", cnt);
	printf("\n sort 후의 배열 내용 : \t");

	for (i = 0; i < MAX; i++)
	{
		printf("%3d", arr[i]);
	}
	putchar('\n');
	return 0;
}
