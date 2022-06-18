#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int danwi[10] = { 50000, 10000, 5000, 1000, 500, 100, 50, 10, 5, 1 };
	int su[10] = { 0 };
	int i, pay;

	printf("금여액 입력 (종료 ^Z) \n");
	while(scanf("%d", &pay) != EOF)
	{
		for (i = 0; i < 10; i++)
		{
			su[i] += pay / danwi[i];
			pay %= danwi[i];
		}
	}
	printf("\n  화폐매수 \n");
	printf("---------------------\n");
	printf("  단 위   수 량 \n");
	printf("---------------------\n");
	for ( i = 0; i < 10; i++)
	{
		printf("%7d : %6d\n", danwi[i], su[i]);
	}
	printf("---------------------\n");

	return 0;
}