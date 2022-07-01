#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void Fibonacci(int cnt);

void main()
{
	int n;
	while (1)
	{
		printf("피보나치의 번째 (0 : 종료) : ");
		scanf("%d", &n);
		if (n <= 0)
			break;
		Fibonacci(n);
	}
}

void Fibonacci(int cnt)
{
	int num1 = 1, num2 = 0, n = 0;
	while (1)
	{
		if (n >= cnt - 1)
			break;
		printf("%d + ", num1);
		num1 += num2;
		num2 = num1 - num2;
		n++;
	}
	printf("%d \n", num1);
}