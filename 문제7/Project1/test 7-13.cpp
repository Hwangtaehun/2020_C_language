#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int PanJung(int jum[]);

void main(void)
{
	int jumsu[3];
	while (1)
	{
		printf("�� ���� ������ �Է��ϼ���.(����� ^Z) ==> ");
		if (scanf("%d%d%d", &jumsu[0], &jumsu[1], &jumsu[2]) == EOF)
			break;
		if (PanJung(jumsu) == 1)
		{
			printf("�հ��Դϴ�.\n");
		}
		else
		{
			printf("���հ��Դϴ�.\n");
		}
	}
}

int PanJung(int jum[])
{
	int av;
	av = (jum[0] + jum[1] + jum[2]) / 3;
	if (av >= 60 && jum[0] >= 40 && jum[1] >= 40 && jum[2] >= 40)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}