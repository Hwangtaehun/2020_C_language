#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, bak, ten, one, fin;


	printf("���ڸ� �� �Է����ּ���.\n");
	scanf("%d", &a);

	if (a >= 100)
	{
		bak = a / 100;
		ten = a / 10 - a / 100 * 10;
		one = a % 10;

		fin = bak * bak * bak + ten * ten * ten + one * one * one;

		if (a == fin)
			printf("�����ý�Ʈ �Դϴ�.\n");
		else
			printf("�����ý�Ʈ�� �ƴմϴ�.\n");
	}
	else
		printf("���ڸ� �� �ƴմϴ�.\n");


	return 0;
}
