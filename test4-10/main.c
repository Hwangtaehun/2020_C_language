#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	printf("�� ������ �Է����ּ���?");
	scanf("%d %d %d", &a, &b, &c);

	if ( a >= 60 && b >= 60 && c >= 60)
	{
		printf("�հ��Դϴ�.\n");
	}
	else
	{
		printf("���հ��Դϴ�.\n");
	}

	return 0;
}
