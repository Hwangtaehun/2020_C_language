#include <stdio.h>
#include <stdlib.h>

int main() {
	float a, total;

	printf("���·��� �Է����ּ���.(���� kWh)\n");
	scanf("%d", &a);

	if (a >= 0 && a <= 50)
	{
		total = a * 34 * 1.1;
	}
	else if (a >= 51 && a <= 100)
	{
		total = (50 * 34 + (a - 50) * 81) * 1.1;
	}
	else if (a > 101)
	{
		total = (50 * 34 + 50 * 81 + (a - 100) * 122) * 1.1;
	}

	printf("%.0f", total);

	return 0;
}
