#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int ban[100], bun[100], weight[100];
	int i, j, cnt = 0, max = 0, maxb, banb, temp;

	printf("반 번호 몸부게를 입력(종료 ^Z) \n");
	while (scanf("%d%d%d", &ban[cnt], &bun[cnt], &weight[cnt]) != EOF)
	{
		cnt++;
	}
	for (i = 0; i < cnt - 1; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (ban[i] > ban[i])
			{
				temp = ban[i];
				ban[i] = ban[j];
				ban[j] = temp;

				temp = bun[i];
				bun[i] = bun[j];
				bun[j] = temp;

				temp = weight[i];
				weight[i] = weight[j];
				weight[j] = temp;
			}
		}
	}
	banb = ban[0];
	maxb = 0;
	printf("-------------------------------------\n");
	printf("\n 반\t번호\t몸무게\n");
	printf("-------------------------------------\n");
	for (i = 0; i < cnt; i++)
	{
		if (ban[i] != banb)
		{
			printf("-------------------------------------\n");
			printf(" %d반\t최대\t%5d\n", banb, max);
			printf("-------------------------------------\n");
			banb = ban[i];
			maxb = 0;
		}
		printf("%3d\t%3d\t%5d\n, ban[i], bun[i], weight[i]");
		if (maxb < weight[i])
			maxb = weight[i];
		if (max < weight[i])
			max = weight[i];
	}
	printf("-------------------------------------\n");
	printf(" %d반\t최대\t%5d\n", banb, maxb);
	printf("-------------------------------------\n");
	printf(" %전체\t최대\t%5d\n", max);
	return 0;
}