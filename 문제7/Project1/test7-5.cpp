#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void BaseConversion(int num, int base);

void main()
{
	int num, jinsu;
	while (1)
	{
		printf("10진수와 변환할 진수를 입력하세요. (종료는 ^Z) ==> ");
		if (scanf("%d %d", &num, &jinsu) == EOF)
			break;

		if (jinsu < 2 || jinsu > 16)
		{
			printf("진법의 범위는 2~16까지 입니다 !!!\n");
			continue;
		}
		BaseConversion(num, jinsu);
	}
}

void BaseConversion(int num, int base)
{
	int num1, n, i;
	char bin[32], ch[17] = "0123456789ABCDEF";
	n = 0;
	num1 = num;
	while (num != 0)
	{
		bin[n] = num % base;
		num /= base;
		n++;
	}
	printf("\n10진수 %d의 %d진수 -->", num1, base);
	for ( i = n-1; i >= 0; i--)
	{
		printf("%2c", ch[bin[i]]);
	}
	printf("\n\n");
}