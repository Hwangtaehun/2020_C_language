#include "my.h"

typedef struct tag_Sung
{
	char name[10];
	int kor;
	int eng;
	int mat;
	int tot;
	float av;
	int rank;
} SUNG;

void Total(SUNG **p);
void Rank(SUNG* p[]);
void Sort(SUNG* p[]);
void Print(SUNG* p[]);
void Print(SUNG* p, int cnt);

int main(int argc, char** argv)
{
	SUNG s[] = { {"�հ�", 100, 100, 100},
				{"����", 60, 50, 80},
				{"�ÿ�", 50, 90, 80},
				{"�ڼ�ȸ", 50, 60, 40},
				{"�ż���", 70, 60, 90} };
	SUNG* p[10];
	int i, cnt;
	cnt = sizeof(s) / sizeof(SUNG);

	for (i = 0; i < cnt; i++)
	{
		p[i] = &s[i];
	}
	p[i] = NULL;

	Total(p);
	Rank(p);
	Sort(p);
	printf("���ĵ� ���� : index �� ����� ��� \n");
	Print(p);
	printf("���ĵ� ���� : index ���� �迭 ������ ������� \n");
	Print(s, cnt);

	return 0;
}

void Total(SUNG** p)
{
	while((*p) != NULL)
	{
		(*p)->tot = (*p)->kor + (*p)->eng + (*p)->mat;
		(*p)->av = (float)(*p)->tot / 3.0f;
		p++;
	}
}

void Rank(SUNG* p[])
{
	int i, j;
	for (i = 0; p[i] != NULL ; i++)
	{
		p[i]->rank = 1;
	}
	for (i = 0; p[i + 1] != NULL; i++)
	{
		for (j = i + 1; p[j] != NULL; j++)
		{
			if (p[i]->tot < p[j]->tot)
			{
				p[i]->rank++;
			}
			else if (p[i]->tot > p[j]->tot)
			{
				p[j]->rank++;
			}
		}
	}
}

void Sort(SUNG* p[])
{
	SUNG* temp;
	int i, j;
	for (i = 0; p[i + 1] != NULL; i++)
	{
		for (j = i + 1; p[j] != NULL; j++)
		{
			if (p[i]->tot < p[j]->tot)
			{
				temp = p[i];
				p[i] = p[j];
				p[j] = temp;
			}
		}
	}
}

void Print(SUNG* p[])
{
	int i = 0;
	printf("%30s\n", "���� ��Ȳ");
	Line(50, '=');
	printf("�̸�    ���� ���� ���� ����   ��� ����\n");
	Line(50, '=');
	while(p[i] != NULL)
	{
		printf("%-8s %5d %5d %5d %5d %8.2f %5d\n", p[i]->name, p[i]->kor, p[i]->eng, p[i]->mat, p[i]->tot, p[i]->av, p[i]->rank);
		i++;
	}
	Line(50, '=');
}

void Print(SUNG* p, int cnt)
{
	SUNG* pt;
	printf("%30s\n", "���� ��Ȳ");
	Line(50, '=');
	printf("�̸�    ���� ���� ���� ����   ��� ����\n");
	Line(50, '=');
	for (pt = p; pt < p + cnt; pt++)
	{
		printf("%-8s %5d %5d %5d %5d %8.2f %5d\n", pt->name, pt->kor, pt->eng, pt->mat, pt->tot, pt->av, pt->rank);
	}
	Line(50, '=');
}

