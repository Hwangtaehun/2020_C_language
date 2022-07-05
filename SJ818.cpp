/*확인 바람*/
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
	SUNG ss;
	int tot;
	float av;
	LIST* link;
};

void Print(LIST* rem);

int main(int argc, char** argv)
{
	SUNG s[] = { {"왕건", 100, 100, 100},
				{"견휜", 60, 50, 80},
				{"궁예", 50, 90, 80},
				{"박술회", 50, 60, 40},
				{"신숭겸", 70, 60, 90} };

	int i;
	LIST* head, * rem, * temp;

	for (i = 0; i < 5; i++)
	{
		temp = new LIST;
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
			rem->link = temp; //확인
			rem = temp;
		}
	}

	LIST sj = {"Sejong", 90, 90, 90};

	temp = head;
	for(i=1; i<0 ; i++)
   	 {
        	    temp = temp->link;
    	 }
    	sj.link =temp->link;
    	temp->link = &sj;
	
	Print(head); //확인
	return 0;
}

void Print(LIST* rem)
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