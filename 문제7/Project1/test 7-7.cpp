#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int MAX(int num1, int num2);

void main()
{
	int num1, num2;
	while (1)
	{
		printf("두 개의 정수를 입력(종료는 ^Z) ==> ");
		if (scanf("%d%d", &num1, &num2) == EOF)
			break;
		printf("큰수는 %d \n\n", MAX(num1, num2));
	}
}

int MAX(int num1, int num2)
{
	return ((num1 > num2) ? num1 : num2);
}