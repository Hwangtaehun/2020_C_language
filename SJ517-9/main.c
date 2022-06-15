#include <stdio.h>
#define MAX 5

int main() {
	int arr[MAX][MAX] = { 0 };
	int i, j, n = 0, cnt = MAX, x = 0, y = -1, s = 1;

	while (1)
	{
		for (i = 0; i < cnt; i++) {
			y += s;
			n++;
			arr[x][y] = n;
		}
		cnt--;
		if (cnt == 0)
			break;
		for ( i = 0; i < cnt; i++)
		{
			x += s;
			n++;
			arr[x][y] = n;
		}
		s = -s;
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
