#include <stdio.h>
#define ROW_CNT 5
#define COL_CNT 5

int main() {
	int score[ROW_CNT][COL_CNT] = { {66,77,88}, {78,57,99}, {65, 47, 34}, {88, 77, 66}, {86, 88, 69} };

	int i, j;

	for (i = 0; i < ROW_CNT; i++)
	{
		for (j = 0; j < COL_CNT - 2; j++)
		{
			score[i][3] += score[i][j];
		}
	}

	//���� ���ϱ� ��� 1
	/*for ( i = 0; i < ROW_CNT; i++)
	{
		score[i][4] = 1;
		for ( j = 0; j < ROW_CNT; j++)
		{
			if (score[i][3] < score[j][3])
			{
				score[i][4]++;
			}
		}
	}*/

	// ���� ���ϱ� ��� 2
	for ( i = 0; i < ROW_CNT; i++)
	{
		score[i][4] = 1;
	}
	for (i = 0; i < ROW_CNT - 1; i++) {
		for ( j = i + 1; j < ROW_CNT; j++)
		{
			if (score[i][3] < score[j][3])
				score[i][4]++;
			else if (score[i][3] > score[j][3])
				score[j][4]++;
		}
	}

	for (i = 0; i < ROW_CNT; i++)
	{
		printf("%5d�� �л��� ���� = %d, ���� = %d\n", i + 1, score[i][3], score[i][4]);
	}

	return 0;
}
