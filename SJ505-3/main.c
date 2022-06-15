#include <stdio.h>
#define ROW_CNT 5
#define COL_CNT 3

int main() {
	int score[ROW_CNT][COL_CNT] = { {66,77,88}, {78,57,99}, {65, 47, 34}, {88, 77, 66}, {86, 88, 69} };

	int i, j, tot = 0;
	float av;

	for ( i = 0; i < ROW_CNT; i++)
	{
		tot = 0;
		for ( j = 0; j < COL_CNT; j++)
		{
			tot += score[i][j];
		}
		av = (float)tot / 3.0f;
		printf("%5d¹ø ÇÐ»ýÀÇ ÃÑÁ¡ = %d, Æò±Õ = %.2f\n", i + 1, tot, av);
	}
	return 0;
}
