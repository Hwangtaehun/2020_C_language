#include <stdio.h>
#define ROW_CNT 5
#define COL_CNT 5

void Print(int score[][COL_CNT], int row, int col);
void Total(int score[][COL_CNT], int row, int col);
void Rank(int score[][COL_CNT], int row, int col);

int main() {
	int score[ROW_CNT][COL_CNT] = { {66,77,88}, {78,57,99}, {65, 47, 34}, {88, 77, 66}, {86, 88, 69} };
	Total(score, ROW_CNT, COL_CNT);
	Rank(score, ROW_CNT, COL_CNT);
	Print(score, ROW_CNT, COL_CNT);
	return 0;
}

void Print(int score[][COL_CNT], int row, int col)
{
    int i;
    for (i = 0; i < ROW_CNT; i++)
	{
		printf("%5d번 학생의 총점 = %d, 석차 = %d\n", i, score[i][col-2], score[i][col-1]);
	}
}

void Total(int score[][COL_CNT], int row, int col)
{
    int i, j;

	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col - 2; j++)
		{
			score[i][col - 2] += score[i][j];
		}
	}
}

void Rank(int score[][COL_CNT], int row, int col)
{
    int i, j;
    for ( i = 0; i < row; i++)
	{
		score[i][col-1] = 1;
	}
	for (i = 0; i < row - 1; i++) {
		for ( j = i + 1; j < row; j++)
		{
			if (score[i][col-2] < score[j][col-2])
				score[i][col-1]++;
			else if (score[i][col-2] > score[j][col-2])
				score[j][col-1]++;
		}
	}
}
