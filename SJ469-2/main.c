#include <stdio.h>
#include <stdlib.h>

int main() {
	int num1 = 1, num2 = 0, num3, tot = 0, cnt = 0;

	do
	{
		num3 = num1 + num2;
		tot += num3;
		cnt++;
		printf(" %d ��° �� = %d \n", cnt, num3);
		num1 = num2;
		num2 = num3;
	} while (cnt < 10);
	printf("��� = %d\n", tot);
	return 0;
}
