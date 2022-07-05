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

int Input(SUNG* s);
void TA(SUNG s[], int cnt);
void Rank(SUNG s[], int cnt);
void Rank_B(SUNG s[], int cnt);
void Print(SUNG s[], int cnt, char str[]);
void Sort_Down(SUNG s[], int cnt);
void Sort_Up(SUNG s[], int cnt);

int main(int argc, char** argv)
{
	int cnt;
	SUNG s[100];

	cnt = Input(s);

	TA(s, cnt);

	Sort_Down(s, cnt);
	Rank_B(s, cnt);
	Print(s, cnt, "내림차순 Sort 후 ");

	return 0;
}

int Input(SUNG* s)
{
	int i = 0;
	printf("이름 국어 영어 수학 점수 입력, 종료는 ctrl+Z \n");
	while (scanf("%s %d %d %d", s[i].name, &s[i].kor, &s[i].eng, &s[i].mat) != EOF)
	{
		i++;
	}
	return i;
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

void Rank_B(SUNG s[], int cnt)
{
	int i, tot = 0, rank1 = 0, rank2 = 0;
	for (i = 0; i < cnt; i++)
	{
		rank1++;
		if (tot != s[i].tot)
		{
			tot = s[i].tot;
			rank2 = rank1;
		}
		s[i].rank = rank2;
	}
}

void Print(SUNG s[], int cnt, char str[])
{
	SUNG* pt;
	int tk = 0, te = 0, tm = 0;

	printf("%25s성적 현황\n", str);
	Line(50, '=');
	printf("이름    국어 영어 수학 총점   평균 석차\n");
	Line(50, '=');
	for (pt = s; pt < s + cnt; pt++)
	{
		printf("%-8s %5d %5d %5d %5d %8.2f %5d\n", pt->name, pt->kor, pt->eng, pt->mat, pt->tot, pt->av, pt->rank);
		tk += pt->kor;
		te += pt->eng;
		tm += pt->mat;
	}
	Line(50, '=');
	printf("%2d명평균%6.1f%6.1f%6.1f\n", cnt, (float)tk / (float)cnt, (float)te / (float)cnt, (float)tm / (float)cnt);
	Line(50, '=');
}

void Sort_Down(SUNG s[], int cnt)
{
	SUNG temp, * sp, * tp;
	for (sp = s; sp < s + cnt - 1; sp++)
	{
		for (tp = sp + 1; tp < s + cnt; tp++)
		{
			if (sp->tot < tp->tot)
			{
				temp = *sp;
				*sp = *tp;
				*tp = temp;
			}
		}
	}
}

void Sort_Up(SUNG s[], int cnt)
{
	SUNG temp;
	for (int i = 0; i < cnt - 1; i++)
	{
		for (int j = i + 1; j < cnt; j++)
		{
			if (s[i].tot > s[j].tot)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}