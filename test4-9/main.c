#include <stdio.h>
#include <stdlib.h>

int main() {
	int year;

	printf("�⵵�� �Է����ּ���.\n");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		printf("�����Դϴ�.\n");
	}

	else
	{
		printf("����Դϴ�.\n");
	}

	return 0;
}
