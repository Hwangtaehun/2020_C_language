#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

char HakJum(int jum);

void main(void)
{
	int jumsu;
	while ( 1 )
	{
		printf("점수를 입력하세요. (종료는 ^Z) ==> ");
		if (scanf("%d", &jumsu) == EOF)
			break;
		printf("%d 점의 학점은 %c입니다. \n", jumsu, HakJum(jumsu));
	}
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