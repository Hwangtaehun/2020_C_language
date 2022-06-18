#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

int main() 
{
	int arr[MAX];
	int* pt, i;
	
	printf("5개의 정수를 입력해주세요.");
	for (i = 0; i < MAX; i++) 
	{
		scanf("%d", &arr[i]);
	}

	pt = arr;
	for (i = 0; i < MAX; i++)
		printf("%5d", *(pt + i));
	putchar('\n');
	for (i = 0; i < MAX; i++) 
	{
		printf("%5d", *pt);
		pt++;
	}
	putchar('\n');

	return 0;
}