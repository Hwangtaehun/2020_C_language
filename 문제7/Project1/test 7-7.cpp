#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int MAX(int num1, int num2);

void main()
{
	int num1, num2;
	while (1)
	{
		printf("�� ���� ������ �Է�(����� ^Z) ==> ");
		if (scanf("%d%d", &num1, &num2) == EOF)
			break;
		printf("ū���� %d \n\n", MAX(num1, num2));
	}
}

int MAX(int num1, int num2)
{
	return ((num1 > num2) ? num1 : num2);
}