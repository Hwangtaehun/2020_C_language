#include <stdio.h>

void sub1(void);
void sub2(void);
void sub3(void);

int main(void) 
{
	printf("���α׷� ����\n");
	printf("sub1() ȣ��\n");
	sub1();

	printf("sub2() ȣ��\n");
	sub2();

	printf("sub3() ȣ��\n");
	sub3();

	printf("���α׷� ��\n");

	return 0;
}

void sub1(void) 
{
	printf("sub1 �Լ� ���� ��\n");
}

void sub2(void)
{
	printf("sub2 �Լ� ���� ��\n");
	printf("sub2() ���� sub3() ȣ��\n");

	sub3();

	printf("sub2 �Լ� ��\n");
}

void sub3(void)
{
	printf("sub3 �Լ� ���� ��\n");
}