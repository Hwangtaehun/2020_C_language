#include <stdio.h>

void hanoi1(int n, int from, int by, int dest);
int hanoi2(int n, int from, int dest);

int main() 
{
	int n, cnt;
	printf("원판의 수 = : ");
	scanf("%d", &n);
	hanoi1(n, 1, 2, 3 );
	printf("-----------------------------------\n");
	cnt = hanoi2(n, 1, 3);
	printf("이동횟수 = %d\n", cnt);
	return 0;
}

void hanoi1(int n, int from, int by, int dest) 
{
	if(n==1)
	{
		printf("%d번 원판을 %d번 기둥에서 %d번 기둥으로 이동 \n", n, from, dest);
	}
	else
	{
		hanoi1(n - 1, from, dest, by);
		printf("%d번 원판을 %d번 기둥에서 %d번 기둥으로 이동 \n", n, from, dest);
		hanoi1(n - 1, by, from, dest);
	}
}

int hanoi2(int n, int from, int dest)
{
	int by, cnt = 0;
	if (n == 1)
	{
		cnt++;
		printf("%d번 원판을 %d번 기둥에서 %d번 기둥으로 이동 \n", n, from, dest);
	}
	else
	{
		by = 6 - from - dest;
		cnt += hanoi2(n - 1, from, by);
		cnt++;
		printf("%d번 원판을 %d번 기둥에서 %d번 기둥으로 이동 \n", n, from, dest);
		cnt += hanoi2(n - 1, by, dest);
	}
	return cnt;
}