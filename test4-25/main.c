#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	printf("           \t�� �� ��\n");
	printf("			�ۼ��� : ���� ����\n");
	for (a = 1; a <= 9; a += 3)
	{
		printf("  �� %d ��\t  �� %d ��\t  �� %d ��\n", a, a+1, a+2);
		for (b = 1; b <= 9; b++)
		{
				printf("%d * %d = %2d\t", a, b, a * b);
				printf("%d * %d = %2d\t", a + 1, b, (a + 1) * b);
				printf("%d * %d = %2d\n", a + 2, b, (a + 2) * b);
		}
	}

	return 0;
}
