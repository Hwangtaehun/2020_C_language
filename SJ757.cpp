#define _CRT_SECURE_NO_WARNINGS
#include "my.h"
#define HEIGHT 7
#define BOTTOM 0

int top[4] = { 0 ,-1, -1, -1 };
int tower[4][HEIGHT];

void hanoi(int n, int from, int by, int dest);
int PushTower(int tno, int data);
int PopTower(int tno);
void DisplayTower(int tno);
void MoveData(int from, int dest);

int main(int argc, char** argv)
{
	int cnt, i;
	do {
		printf("원판의 수 ( 1 - %d ) : ", HEIGHT);
		scanf("%d", &cnt);
	} while (cnt <= 0 || cnt > HEIGHT);

	for(i = cnt; i > 0; i--)
	{
		PushTower(1, i);
	}
	DisplayTower(1);
	DisplayTower(2);
	DisplayTower(3);
	hanoi(cnt, 1, 2, 3);
	return 0;
}

void MoveData(int from, int dest)
{
	int data;
	data = PopTower(from);
	DisplayTower(from);
	PushTower(dest, data);
	DisplayTower(dest);
}

int PushTower(int tno, int data)
{
	if (top[tno] >= HEIGHT - 1)
	{
		printf("Stack이 넘쳐요.\n");
		return -1;
	}
	top[tno]++;
	tower[tno][top[tno]] = data;
	return data;
}

int PopTower(int tno) 
{
	int data;
	if (top[tno] < BOTTOM)
	{
		printf("Stack에 자료가 없어요.\n");
		return -1;
	}
	data = tower[tno][top[tno]];
	tower[tno][top[tno]] = 0;
	top[tno]--;
	return data;
}

void hanoi(int n, int from, int by, int dest)
{
	if (n == 1)
	{
		MoveData(from, dest);
	}
	else
	{
		hanoi(n - 1, from, dest, by);
		MoveData(from, dest);
		hanoi(n - 1, by, from, dest);
	}
}

void DisplayTower(int tno)
{
	int y;
	for (y = 0; y < HEIGHT; y++)
	{
		gotoxy((tno) * 10, y * 2 + 3);
		if (tower[tno][HEIGHT - y - 1] == 0)
			printf(" ");
		else
			printf("%d", tower[tno][HEIGHT - y - 1]);
	}
	gotoxy((tno) * 10 - 2, y * 2 + 3);
	Line(6, '=');
	gotoxy((tno) * 10 - 2, y * 2 + 4);
	printf("기둥 %d", tno);
	printf("\n");
	Sleep(300);
}