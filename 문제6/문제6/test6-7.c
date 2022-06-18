#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 5

int main()
{
	int arr[MAX][MAX] = { 0 };
	int i, j, n = 0;
	int(*pt2)[MAX], * pt1;

	pt2 = arr;
	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			n++;
			*(*pt2 + j) = n;
		}
		pt2++;
	}

	pt1 = (int*)arr;
	for (i = 0; i < MAX * MAX; i++)
	{
		printf("%3d", *pt1);
		pt1++;
		
	}
	putchar('\n');

	return 0;
}