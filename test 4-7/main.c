#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, avl;

	printf("�� ������ �Է����ּ���?");
	scanf("%d %d %d", &a, &b, &c);

	avl = (a + b + c) / 3;

	if (avl >= 60 && a >= 40 && b >= 40 && c >= 40)
	{
		printf("�հ��Դϴ�.\n");
	}
	else
	{
		printf("���հ��Դϴ�.\n");
	}

	return 0;
}
