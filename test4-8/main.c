#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;

	printf("���ڸ� �Է����ּ���.\n");
	a = getchar();

	if (a % 2 == 0 && a % 3 == 0)
	{
		printf("�½��ϴ�.\n");
	}
	else
	{
		printf("Ʋ���ϴ�.\n");
	}

	return 0;
}
