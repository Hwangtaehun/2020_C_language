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
}; //수정

void Print(struct LIST* rem); //수정

int main(int argc, char** argv)
{
	struct SUNG s[] = { {"왕건", 100, 100, 100},
				{"견휜", 60, 50, 80},
				{"궁예", 50, 90, 80},
				{"박술회", 50, 60, 40},
				{"신숭겸", 70, 60, 90} };

	int i;
	struct  LIST* head, * rem, * temp; //수정

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

void Print(struct LIST* rem) //수정
{
	printf("%26s\n", "성적 현황");
	Line(43, '=');
	printf(" 이 름  국어 영어 수학 총점   평균 \n");
	Line(43, '=');
	while (rem != NULL)
	{
		printf(" %-8s %5d %5d %5d %5d %8.2f \n", rem->ss.name, rem->ss.kor, rem->ss.eng, rem->ss.mat, rem->tot, rem->av);
		rem = rem->link;
	}
	Line(43, '=');

}