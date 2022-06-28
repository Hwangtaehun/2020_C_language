#include<stdio.h>

void sub();

int e;

int main(int argc, char **argv)
{
	auto int a;
	static int s;
	int* pt;
	pt = new int;
	printf("전역 변수  e 의 번지 = %u, 값 = %d \n", &e, e);
	printf("전역 변수  s 의 번지 = %u, 값 = %d \n", &s, s);
	printf("전역 변수  a 의 번지 = %u, 값 = %d \n", &a, a);
	printf("동적Memory pt의 번지 = %u, 값 = %d \n", pt, *pt);
	sub();
	return 0;
}

void sub()
{
	auto int sa;
	static int ss;
	printf("sub의 정적 변수 ss의 번지 = %u, 값 = %d \n", &ss, ss);
	printf("sub의 정적 변수 sa의 번지 = %u, 값 = %d \n", &sa, sa);
}