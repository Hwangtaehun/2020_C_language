#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char pum[100], ctemp;
	int su[100], danga[100];
	int i, j, cnt = 0, kum, hap = 0, temp;
	printf("상품명(1문자) 수량 단가를 입력(종료 0 0 0) \n");
	while (1)
	{
		scanf(" %c%d%d", &pum[cnt], &su[cnt], &danga[cnt]);
		if (pum[cnt] == '0')
			break;
		cnt++;
	}
	for (i = 0; i < cnt - 1; i++)
	{
		for (j = i + 1; j < cnt; j++)
		{
			if (pum[i] > pum[j]) 
			{
				temp = pum[i];
				pum[i] = pum[j];
				pum[j] = temp;

				temp = su[i];
				su[i] = su[j];
				su[j] = temp;

				temp = danga[i];
				danga[i] = danga[j];
				danga[j] = temp;
			}
		}
	}
	printf("\n-------------------------------------\n");
	printf("품명\t수량\t단가\t   금액\n");
	printf("-------------------------------------\n");

	for (i = 0; i < cnt; i++)
	{
		kum = su[i] * danga[i];
		hap += kum;
		printf("%c\t%3d\t%3d\t%7d\n", pum[i], su[i], danga[i], kum);
	}
	printf("\n-------------------------------------\n");
	printf("합계\t\t\t%7d\n", hap);
	printf("-------------------------------------\n");

	return 0;
}