#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <string.h>

struct PAN
{
	char name[10];
	int su;
	int dan;
};

void Sort(PAN p[], int cnt);
void Print(PAN p[], int cnt);

int main(void)
{
	PAN s[] = { {"�ڷ�����", 10, 150000},
				{"����", 7, 100000},
				{"ī�޶�", 6, 120000},
				{"ķ�ڴ�", 5, 500000},
				{"�ڷ�����", 11, 150000},
				{"����", 5, 100000},
				{"ī�޶�", 6, 120000},
				{"ķ�ڴ�", 7, 500000},
				{"�ڷ�����", 12, 150000},
				{"����", 1, 100000},
				{"ī�޶�", 2, 120000},
				{"ķ�ڴ�", 3, 500000} };
	int cnt;
	cnt = sizeof(s) / sizeof(PAN);
	Sort(s, cnt);
	Print(s, cnt);

	return 0;
}

void Sort(PAN p[], int cnt)
{
	PAN temp;
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if ( strcmp(p[i].name, p[j].name) > 0 )
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void Print(PAN p[], int cnt)
{
	int i, kum, ptot, gtot;
	char pname[10], pname1[10];
	printf("%30s\n", "�Ǹ�����ǥ");
	printf(" ǰ ��  �� ��\t �ܰ�\t �Ǹž�\n");
	strcpy(pname, p[0].name);
	strcpy(pname1, p[0].name);
	ptot = gtot = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(pname, p[i].name) != 0)
		{
			printf("         ǰ���          %8d\n", ptot);
			strcpy(pname, p[i].name);
			strcpy(pname1, p[i].name);
			gtot += ptot;
			ptot = 0;
		}
		kum = p[i].su * p[i].dan;
		printf(" %-8s %5d\t%5d\t%8d\n", pname1, p[i].su, p[i].dan, kum);
		strcpy(pname1, "");
		ptot += kum;
	}
	printf("	ǰ���			%8d\n", ptot);
	gtot += ptot;
	printf("	��  ��			%8d\n", gtot);
	printf("	��  ��			%8d\n", gtot/cnt);
}