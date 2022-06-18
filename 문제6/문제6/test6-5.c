#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

int main()
{
	int arr[MAX][MAX] = { 0 };
	int i, j, n = 0;
	int(*pt)[MAX];

	pt = arr;
	for (i = 0; i < MAX; i++) 
	{
		for (j = 0; j < MAX; j++) 
		{
			n++;
			*(*pt + j) = n;
		}
		pt++;
	}

	pt = arr;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			printf("%3d", *(*pt + j));
		}
		pt++;
		printf("\n");
	}

	return 0;
}