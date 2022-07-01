#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void MoneyPrint(int num);

void main()
{
	int num;
	while (1)
	{
		printf("정수를 입력하세요. (종료는 ^Z) ==> ");
		if (scanf("%d", &num) == EOF)
			break;
		printf("변환 후 내용 : ");
		MoneyPrint(num);
	}
}

void MoneyPrint(int num)
{
	int cnt = 0, weight = 1;
	while (weight <= num)
	{
		weight *= 10;
		cnt++;
	}
	weight /= 10;
	printf("\\");
	while (weight > 1)
	{
		printf("%d", num / weight);
		num %= weight;
		weight /= 10;
		cnt--;
		if (cnt % 3 == 0)
			printf(",");
	}
	printf("%d\n\n", num);
}