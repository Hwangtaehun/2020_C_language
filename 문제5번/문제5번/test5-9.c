#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char jdab[26] = "1234123412341234123412341";
	char name[100][10], idab[100][26], hak;
	int i, j, cnt = 0, jcnt, no[100], jumsu;
	printf("��ȣ �̸� ���(25��) �Է� (���� ^Z) \n");
	while (scanf("%d%s%s", &no[cnt], name[cnt], idab[cnt]) != EOF)
		cnt++;
	printf("\n  ���� ���ǥ \n");
	printf("----------------------");
	printf("--------------------\n");
	printf("��ȣ �� ��    ");
	for (i = 1; i <= 25; i++)
		printf("%2d", i);
	printf("  ���� ���� \n");
	printf("----------------------");
	printf("--------------------\n");
	for (i = 0; i < cnt; i++)
	{
		jcnt = 0;
		for (j = 0; j < 25; j++)
		{
			if (idab[i][j] == jdab[j]) 
			{
				jcnt++;
				printf(" O");
			}
			else
			{
				printf(" X");
			}
		}
		jumsu = jcnt * 4;
		if (jumsu >= 90)
			hak = 'A';
		else if (jumsu >= 80)
			hak = 'B';
		else if (jumsu >= 70)
			hak = 'C';
		else if (jumsu >= 60)
			hak = 'D';
		else
			hak = 'F';
		printf("   %3d   %c \n", jumsu, hak);
	}
	printf("----------------------");
	printf("--------------------\n");
}