#include <stdio.h>

int main() {
	int ka[2][3] = { {1,2},{3,4} };
	int kb[2][3] = { 1,2,3,4 };

	int i, j;
	printf("\n ka �迭�� ���� \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%5d", ka[i][j]);
		}
		printf("\n");
	}

	printf("\n kb �迭�� ���� \n");
	for (i = 0; i < 2; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%5d", kb[i][j]);
		}
		printf("\n");
	}
	return 0;
}
