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
	PAN s[] = { {"텔레비전", 10, 150000},
				{"비디오", 7, 100000},
				{"카메라", 6, 120000},
				{"캠코더", 5, 500000},
				{"텔레비전", 11, 150000},
				{"비디오", 5, 100000},
				{"카메라", 6, 120000},
				{"캠코더", 7, 500000},
				{"텔레비전", 12, 150000},
				{"비디오", 1, 100000},
				{"카메라", 2, 120000},
				{"캠코더", 3, 500000} };
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
	printf("%30s\n", "판매집계표");
	printf(" 품 명  수 량\t 단가\t 판매액\n");
	strcpy(pname, p[0].name);
	strcpy(pname1, p[0].name);
	ptot = gtot = 0;
	for (i = 0; i < cnt; i++)
	{
		if (strcmp(pname, p[i].name) != 0)
		{
			printf("         품목계          %8d\n", ptot);
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
	printf("	품목계			%8d\n", ptot);
	gtot += ptot;
	printf("	합  계			%8d\n", gtot);
	printf("	평  균			%8d\n", gtot/cnt);
}