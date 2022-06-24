#include <stdio.h>

void hanoi1(int n, int from, int by, int dest);
int hanoi2(int n, int from, int dest);

int main() 
{
	int n, cnt;
	printf("������ �� = : ");
	scanf("%d", &n);
	hanoi1(n, 1, 2, 3 );
	printf("-----------------------------------\n");
	cnt = hanoi2(n, 1, 3);
	printf("�̵�Ƚ�� = %d\n", cnt);
	return 0;
}

void hanoi1(int n, int from, int by, int dest) 
{
	if(n==1)
	{
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �̵� \n", n, from, dest);
	}
	else
	{
		hanoi1(n - 1, from, dest, by);
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �̵� \n", n, from, dest);
		hanoi1(n - 1, by, from, dest);
	}
}

int hanoi2(int n, int from, int dest)
{
	int by, cnt = 0;
	if (n == 1)
	{
		cnt++;
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �̵� \n", n, from, dest);
	}
	else
	{
		by = 6 - from - dest;
		cnt += hanoi2(n - 1, from, by);
		cnt++;
		printf("%d�� ������ %d�� ��տ��� %d�� ������� �̵� \n", n, from, dest);
		cnt += hanoi2(n - 1, by, dest);
	}
	return cnt;
}