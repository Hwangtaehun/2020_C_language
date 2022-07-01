#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void Compute(int num1, int num2);

void main()
{
	int a, b;
	while (1)
	{
		printf("계산 할 수 두개 입력 (0 0:종료) : ");
		scanf("%d%d", &a, &b);
		if (a == 0 && b == 0)
			break;
		Compute(a, b);
	}
}

void Compute(int num1, int num2)
{
	printf("%d + %d = %3d\n", num1, num2, num1 + num2);
	printf("%d - %d = %3d\n", num1, num2, num1 - num2);
	printf("%d * %d = %3d\n", num1, num2, num1 * num2);
	printf("%d / %d = %3d\n", num1, num2, num1 / num2);
}