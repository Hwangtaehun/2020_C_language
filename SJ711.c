#include <stdio.h>

void sub1(void);
void sub2(void);
void sub3(void);

int main(void) 
{
	printf("프로그램 시작\n");
	printf("sub1() 호출\n");
	sub1();

	printf("sub2() 호출\n");
	sub2();

	printf("sub3() 호출\n");
	sub3();

	printf("프로그램 끝\n");

	return 0;
}

void sub1(void) 
{
	printf("sub1 함수 실행 중\n");
}

void sub2(void)
{
	printf("sub2 함수 실행 중\n");
	printf("sub2() 에서 sub3() 호출\n");

	sub3();

	printf("sub2 함수 끝\n");
}

void sub3(void)
{
	printf("sub3 함수 실행 중\n");
}