#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;

	printf("�ϳ��� ���ڸ� �Է����ּ���.");
	c = getchar();

	switch (c)
	{
	case'I':
	case'i':
		printf("������ �����ϼ̽��ϴ�.\n");
		break;
	case'M':
	case'm':
		printf("������ �����ϼ̽��ϴ�.\n");
		break;
	case'D':
	case'd':
		printf("������ �����ϼ̽��ϴ�.\n");
		break;
	default:
		printf("�߸� �Է��Ͽ����ϴ�.\n");
	}

	return 0;
}
