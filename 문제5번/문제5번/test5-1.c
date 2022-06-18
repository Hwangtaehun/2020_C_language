#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 7

int main() {
	int arr[MAX];
	int i, j, temp, hap = 0;

	printf("7개의 점수를 입력해주세요.");
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
	printf("총점 = %d, 평균 = %.2f\n", hap, (float)hap / (float)(MAX - 2));
	return 0;
}