#include <stdio.h>
#include <stdlib.h>

int main() {
	int year, month, JulianDay, i, pos;
	int days[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (1)
	{
		printf("년 월을 입력하세요.(종료는 0 0) : ");
		scanf("%d%d", &year, &month);

		if (year == 0)
			break;

		if (month < 1 || month > 12)
		{
			printf("월은 1월 부터 12까지 !!\n");
			continue;
		}

		JulianDay = (year - 1) * 365 + (year - 1) / 4 - (year - 1) / 100 + (year - 1) / 400;
		days[2] = (year % 4 == 0 && year % 100 != 0 || year % 400 == 0) ? 29 : 28;
		for ( i = 0; i < month; i++)
		{
			JulianDay += days[i];
		}
		JulianDay += 1;

		pos = JulianDay % 7;
		printf("\n		%4d년 %2d월 \n", year, month);
		printf("-----------------------------------------\n");
		printf("   일   월   화   수   목   금   토 \n");
		printf("-----------------------------------------\n");
		for (i = 0; i < pos; i++)
		{
			printf("     ");
		}
		for ( i = 1; i <= days[month]; i++)
		{
			printf("%5d", i);
			if (++pos % 7 == 0)
			{
				printf("\n");
			}
		}
		printf("\n-----------------------------------------\n\n");
	}
	return 0;
}
