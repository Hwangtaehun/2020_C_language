#include<stdio.h>

void sub();

int e;

int main(int argc, char **argv)
{
	auto int a;
	static int s;
	int* pt;
	pt = new int;
	printf("���� ����  e �� ���� = %u, �� = %d \n", &e, e);
	printf("���� ����  s �� ���� = %u, �� = %d \n", &s, s);
	printf("���� ����  a �� ���� = %u, �� = %d \n", &a, a);
	printf("����Memory pt�� ���� = %u, �� = %d \n", pt, *pt);
	sub();
	return 0;
}

void sub()
{
	auto int sa;
	static int ss;
	printf("sub�� ���� ���� ss�� ���� = %u, �� = %d \n", &ss, ss);
	printf("sub�� ���� ���� sa�� ���� = %u, �� = %d \n", &sa, sa);
}