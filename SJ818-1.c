#include "my.h"

struct SUNG
{
	char name[10];
	int kor;
	int eng;
	int mat;
};

struct LIST
{
	struct SUNG ss;
	int tot;
	float av;
	struct LIST* link;
}; //����

void Print(struct LIST* rem); //����

int main(int argc, char** argv)
{
	struct SUNG s[] = { {"�հ�", 100, 100, 100},
				{"����", 60, 50, 80},
				{"�ÿ�", 50, 90, 80},
				{"�ڼ�ȸ", 50, 60, 40},
				{"�ż���", 70, 60, 90} };

	int i;
	struct  LIST* head, * rem, * temp; //����

	for (i = 0; i < 5; i++)
	{
		temp = (struct LIST *)malloc(sizeof(struct LIST));
		temp->ss = s[i];
		temp->link = NULL;
		temp->tot = temp->ss.kor + temp->ss.eng + temp->ss.mat;
		temp->av = (float)temp->tot / 3.0f;
		if (i == 0)
		{
			head = rem = temp;
		}
		else
		{
			rem->link = temp;
			rem = temp;
		}
	}

	Print(head);
	return 0;
}

void Print(struct LIST* rem) //����
{
	printf("%26s\n", "���� ��Ȳ");
	Line(43, '=');
	printf(" �� ��  ���� ���� ���� ����   ��� \n");
	Line(43, '=');
	while (rem != NULL)
	{
		printf(" %-8s %5d %5d %5d %5d %8.2f \n", rem->ss.name, rem->ss.kor, rem->ss.eng, rem->ss.mat, rem->tot, rem->av);
		rem = rem->link;
	}
	Line(43, '=');

}