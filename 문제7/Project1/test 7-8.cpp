#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void LcmGcm(int* pa, int* pb);

void main()
{
	int num1, num2;
	while (1)
	{
		printf("두 개의 정수를 입력(종료는 ^Z) ==> ");
		if (scanf("%d%d", &num1, &num2) == EOF)
			break;
		LcmGcm(&num1, &num2);
		printf("gcm = %d, lcm = %d\n\n", num1, num2);
	}
}

void LcmGcm(int* pa, int* pb)
{
	int a, b, kun, jak, na;
	a = *pa;
	b = *pb;

	if (a > b)
		kun = a, jak = b;
	else
		kun = b, jak = a;
	while ((na = kun % jak) != 0)
	{
		kun = jak;
		jak = na;
	}
	*pa = jak;
	*pb = a * b / *pa;
}