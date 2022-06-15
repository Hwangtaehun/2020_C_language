#include <stdio.h>
#define MAX 5

int main() {
	int arr[MAX][MAX] = { 0 };
	int i, j, n = 0, start, end;
	start = end = MAX / 2;

	for (i = MAX - 1; i >= 0; i--)
	{
		for (j = start; j <= end; j++)
		{
			n++;
			arr[j][i] = n;
		}
		if (i > MAX / 2)
		{
			start--;
			end++;
		}
		else
		{
			start++;
			end--;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			if (arr[i][j] == 0)
			{
				printf("   ");
			}
			else
			{
				printf("%3d", arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
