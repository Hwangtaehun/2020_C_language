#include <stdio.h>
#define MAX 5

int main() {
	int arr[MAX][MAX] = { 0 };
	int i, j, n = 0, x = 0, y = MAX / 2, bx, by;

	while (1)
	{
		n++;
		arr[x][y] = n;

		bx = x;
		by = y;

		if (n >= MAX * MAX)
			break;

		if (x > 0)
			x--;
		else
			x = MAX - 1;

		if (y < MAX - 1)
			y++;
		else
			y = 0;

		if (arr[x][y] != 0)
		{
			x = bx + 1;
			y = by;
		}
	}

	for (i = 0; i < MAX; i++)
	{
		for (j = 0; j < MAX; j++)
		{
			{
				printf("%3d", arr[i][j]);
			}
		}
		printf("\n");
	}
	return 0;
}
