#include <stdio.h>
#define MAX 5

void Print(int k[][5]);

int main() 
{
	int arr[MAX][MAX] = { 0 };
	int x = 0, y = MAX / 2, n = 0, bx, by;

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
	
	Print(arr);

	return 0;
}

void Print(int k[][5])
{
	int i, j;
	for ( i = 0; i < 5; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("%3d", k[i][j]);
		}
		printf("\n");
	}
}
