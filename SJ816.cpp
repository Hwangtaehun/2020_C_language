#include <stdio.h>

struct JUSO
{
	char zip[7];
	char addr[20];
	char tel[13];
};

struct SUNG_A
{
	char name[10];
	int kor;
	int eng;
	int mat;
};

struct SUNG_B
{
	int tot;
	float av;
	int rank;
};

struct SUNGJUK
{
	JUSO jj;
	SUNG_A aa;
	SUNG_B bb;
};

int main(int argc, char** argv)
{
	JUSO ju = { "3611-1", "사직동", "111-2222" };
	SUNG_A sa = { "왕건", 88, 99, 100 };
	SUNGJUK sj;

	sj.jj = ju;
	sj.aa = sa;

	sj.bb.tot = sj.aa.kor + sj.aa.eng + sj.aa.mat;
	sj.bb.av = (float)sj.bb.tot / 3.0f;

	printf(" 주소 : %s %s \n", sj.jj.zip, sj.jj.addr);
	printf(" 전화 : %s \n", sj.jj.tel);
	printf(" 이름 : %s \n", sj.aa.name);
	printf(" 총점 : %d \n", sj.bb.tot);
	printf(" 평균 : %.2f \n", sj.bb.av);

	return 0;
}