#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 7

int main() {
	int arr[MAX];
	int i, j, temp, hap = 0;

	printf("7���� ������ �Է����ּ���.");
	for ( i = 0; i < MAX; i++)
	{
		scanf("%d", arr + i);
	}

	for ( i = 0; i < MAX - 1; i++)
	{
		for ( j = i+1; j < MAX; j++)
		{
			if (arr[i] > arr[j]) {
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}

		}
	}
	for (i = 1; i < MAX - 1; i++)
	{
		hap += arr[i];
	}
	printf("���� = %d, ��� = %.2f\n", hap, (float)hap / (float)(MAX - 2));
	return 0;
}