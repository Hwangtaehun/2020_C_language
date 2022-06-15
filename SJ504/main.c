#include <stdio.h>
#define M 3

int main() {
	int k[M][M];
	int i, j, cnt = 0;

	for ( i = 0; i < M; i++)
	{
		for ( j = 0; j < M; j++)
		{
			cnt++;
			k[i][j] = cnt;
		}
	}

	for (i = 0; i < M; i++)
	{
		for (j = 0; j < M; j++)
		{
			printf("%5d", k[i][j]);
		}
		printf("\n");
	}
	return 0;
}
