#include "my.h"
#include <ctype.h>

typedef struct tag_Sung
{
	int ban;
	int bun;
	char name[10];
	int kor;
	int eng;
	int mat;
	int tot;
	float av;
	int rank;
} SUNG;

void WriteFile(char* mode);
void ReadFile();
int FileToArray(SUNG s[]);
void Total(SUNG* s, int cnt);
void Sort(SUNG s[], int cnt);
void Rank(SUNG s[], int cnt);
void Print(SUNG* s, int cnt);
char HakJum(int jum);

int main(void)
{
	char ch;
	while (1)
	{
		Line(63, '*');
		printf("자료 삭제 후 입력 : w, 자료추가 : a, 자료출력 : r, 종료 : q \n");
		Line(63, '*');
		printf("원하는 작업을 선택하세요 --> ");
		ch = getchar();
		_flushall();
		switch (tolower(ch))
		{
		case 'w':
			WriteFile("w");
			break;
		case 'a':
			WriteFile("a");
			break;
		case 'r':
			WriteFile(" ");
			break;
		case 'q':
			return 0;
		}
	}
	return 0;
}

void WriteFile(char* mode)
{
	SUNG s;
	FILE* fp;
	if ((fp = fopen("sungjuk.dat",mode)) == NULL)
	{
		printf(" 출력 File open error \n");
		exit(0);
	}
	Line(56, '-');
	printf("반 번호 이름 국어점수 영어점수 수학 점수 입력 종료는 ^Z\n");
	Line(56, '-');
	while (scanf("%d%d%s%d%d%d", &s.ban, &s.bun, &s.name, &s.kor, &s.eng, &s.mat) != EOF)
	{
		fprintf(fp, "%d %d %-8s %3d %3d %3d\n", s.ban, s.bun, s.name, s.kor, s.eng, s.mat);
	}
	fclose(fp);
}

void ReadFile()
{
	SUNG s[100];
	int cnt;
	cnt = FileToArray(s);
	Total(s, cnt);
	Sort(s, cnt); 
	Rank(s, cnt); 
	Print(s, cnt);
}

int FileToArray(SUNG s[])
{
	FILE* fp;
	int i = 0;
	if ((fp = fopen("sungjuk.dat", mode)) == NULL)
	{
		printf(" 입력 File open error \n");
		exit(0);
	}
	while (fscanf(fp, "%d %d %s %d %d %d", &s[i].ban, &s[i].bun, &s[i].name, &s[i].kor, &s[i].eng, &s[i].mat) != EOF)
	{
		i++;
	}
	fclose(fp);
	return 0;
}

void Total(SUNG* s, int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		s[i].tot = s[i].kor + s[i].eng + s[i].mat;
		s[i].av = (float)s[i].tot / 3.0f;
	}
}

void Sort(SUNG s[], int cnt)
{
	SUNG temp;
	int i, j;
	for (i = 0; i < cnt - 1; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (s[i].ban > s[j].ban)
			{
				temp = s[i];
				s[i] = s[j];
				s[j] = temp;
			}
		}
	}
}

void Rank(SUNG s[], int cnt)
{
	int i, j;
	for (i = 0; i < cnt; i++)
	{
		s[i].rank = 1;
	}
	for (i = 0; i < cnt - 1; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (s[i].tot < s[j].tot)
			{
				s[i].rank++;
			}
			else if (s[i].tot > s[j].tot)
			{
				s[j].rank++;
			}
		}
	}
}

void Print(SUNG* s, int cnt)
{
	SUNG* pt;
	int tk = 0, te = 0, tm = 0, gk = 0, ge = 0, gm = 0;
	int iban, bcnt, max = -1, min = 999;
	printf("\n\n%30s\n", "성적 현황");
	Line(63, '=');
	printf("반 번호 이름 국어 영어 수학 총점 평균 석차 학점 \n");
	Line(63, '=');
	iban = s->ban;
	bcnt = 0;
	for (pt = s; pt < s + cnt; pt++)
	{
		if (iban != pt->ban)
		{
			Line(63, '-');
			printf("%2d반 평균 %6.1f %6.1f %6.1f \n", iban, (float)tk / (float)bcnt, (float)te / (float)bcnt, (float)tm / (float)bcnt);
			Line(63, '-');
			iban = pt->ban;
			gk += tk;
			ge += te;
			gm += tm;
			tk = te = tm = bcnt = 0;
		}
		printf("%2d%3d%-8s%6d%6d%6d%6d%8.2f%3d%c\n", pt->ban, pt->bun, pt->name, pt->kor, pt->eng, pt->mat, pt->tot, pt->av, pt->rank, HakJum((int)pt->av));
		if (max < pt->tot)
			max = pt->tot;
		if (min > pt->tot)
			min = pt->tot;
		tk += pt->kor;
		te += pt->eng;
		tm += pt->mat;
		bcnt++;
	}
	Line(63, '-');
	printf("%2d반 평균 %6.1f %6.1f %6.1f \n", iban, (float)tk / (float)bcnt, (float)te / (float)bcnt, (float)tm / (float)bcnt);
	gk += tk;
	ge += te;
	gm += tm;
	Line(63, '=');
	printf("전체 평균(%2d명) %6.1f %6.1f %6.1f \n", cnt, (float)gk / (float)cnt, (float)ge / (float)cnt, (float)gm / (float)cnt);
	printf("최고 점수   %33\n", max);
	printf("최저 점수   %33\n", min);
	Line(63, '=');
	printf("\n");
}

char HakJum(int jum)
{
	char hak;
	if (jum >= 90)
		hak = 'A';
	else if (jum >= 80)
		hak = 'B';
	else if (jum >= 70)
		hak = 'C';
	else if (jum >= 60)
		hak = 'D';
	else
		hak = 'F';
	return hak;
}