#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char jdab[11] = "1234123412";
	char name[100][10], idab[100][11];
	int i, j, cnt = 0, jcnt;
	printf("�̸� ��� �Է� (���� ^Z) \n");
	while (scanf("% s % s", name[cnt], idab[cnt]) != EOF)
		cnt++;
	printf("\n  ���� ���ǥ \n");
	printf("--------------------\n");
	printf("�� ��      ���� \n");
	printf("--------------------\n");
	for ( i = 0; i < cnt; i++)
	{
		jcnt = 0;
		for ( j = 0; j < 10; j++)
		{
			if (idab[i][j] == jdab[j])
				jcnt++;
		}
		printf("%-10s %3d\n", name[i], jcnt * 10);
	}
	printf("--------------------\n");
}