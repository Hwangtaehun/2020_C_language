#include <stdio.h>

int main() {
	int aa[3][3] = { {1,2,3},{4,5,6},{7,8,9} }, bb[4][4] = { 0 };
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			bb[j][i] = aa[i][j];
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			bb[i][3] += bb[i][j];
			bb[3][j] += bb[i][j];
			bb[3][3] += bb[i][j];

		}
	}

	for (i = 0; i < 4; i++)
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", bb[i][j]);
		}
		printf("\n");
	}

	return 0;
}
