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

void TA(SUNG s[], int cnt);
void Rank(SUNG s[], int cnt);
void Print(SUNG s[], int cnt, char str[]);
void Sort_Down(SUNG s[], int cnt);
void Sort_Up(SUNG s[], int cnt);

int main(int argc, char** argv)
{
	int cnt;
	SUNG s[] = { {"�հ�", 100, 100, 100},
				{"����", 60, 50, 80},
				{"�ÿ�", 50, 90, 80},
				{"�ڼ�ȸ", 50, 60, 40},
				{"�ż���", 70, 60, 90} };
	cnt = sizeof(s) / sizeof(SUNG);

	TA(s, cnt);
	Rank(s, cnt);
	Print(s, cnt, "Sort ���� ");

	Sort_Down(s, cnt);
	Print(s, cnt, "�������� Sort �� ");

	Sort_Up(s, cnt);
	Print(s, cnt, "�������� Sort �� ");


	return 0;
}

void TA(SUNG s[], int cnt)
{
	SUNG* pt;
	for (pt = s; pt < s + cnt; pt++)
	{
		pt->tot = pt->kor + pt->eng + pt->mat;
		pt->av = (float)pt->tot / 3.0f;
	}
}

void Rank(SUNG s[], int cnt)
{
	SUNG* sp, * tp;
	for (sp = s; sp < s + cnt; sp++)
	{
		sp->rank = 1;
	}
	for (sp = s; sp < s + cnt - 1; sp++)
	{
		for (tp = sp + 1; tp < s + cnt; tp++)
		{
			if (sp->tot < tp->tot)
			{
				sp->rank++;
			}
			else if (sp->tot > tp->tot)
			{
				tp->rank++;
			}
		}
	}
}

void Print(SUNG s[], int cnt, char str[])
{
	SUNG* pt;
	printf("%25s���� ��Ȳ\n", str);
	Line(50, '=');
	printf("�̸�    ���� ���� ���� ����   ��� ����\n");
	Line(50, '=');
	for (pt = s; pt < s + cnt; pt++)
	{
		printf("%-8s %5d %5d %5d %5d %8.2f %5d\n", pt->name, pt->kor, pt->eng, pt->mat, pt->tot, pt->av, pt->rank);
	}
	Line(50, '=');
}

void Sort_Down(SUNG s[], int cnt)
{
	SUNG temp;
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (s[i].tot < s[j].tot)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

void Sort_Up(SUNG s[], int cnt)
{
	SUNG temp, * sp, * tp;
	for (sp = s; sp < s + cnt - 1; sp++)
	{
		for (tp = sp + 1; tp < s + cnt; tp++)
		{
			if (sp->tot > tp->tot)
			{
				temp = *sp;
				*sp = *tp;
				*tp = temp;
			}
		}
	}
}