#include <stdio.h>
#include <stdlib.h>

int main() {
	int number, tot = 0, cnt = 0, money, sw = 0, MonetaryUnit = 10000;

	printf("금액 : ");
	scanf("%d", &money);

	do {
		number = money / MonetaryUnit;
		if (number != 0)
			printf("%5d원 매수 = %3d \n", MonetaryUnit, number);
		money = money % MonetaryUnit;
		if (sw == 0) {
			MonetaryUnit /= 2;
			sw = 1;
		}
		else
		{
			MonetaryUnit /= 5;
			sw = 0;
		}
	} while (money > 0);
	return 0;
}
