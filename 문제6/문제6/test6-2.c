#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 10

int main()
{
	double arr[MAX];
	double* pt;
	int i, j = 0;

	printf("5개의 정수를 입력해주세요.");
	for (i = 0; i < MAX; i++)
	{
		scanf("%lf", &arr[i]);
	}

	pt = arr;
	for (i = 0; i < MAX - 6; i++)
	{
		j += i;
		printf("%8.2lf", *(pt + j));
	}
	putchar('\n');

	return 0;
}