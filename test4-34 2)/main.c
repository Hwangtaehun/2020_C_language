#include <stdio.h>
#include <stdlib.h>

int main() {
	int num1, num2, num3, n, a;
	num1 = 1;
	num2 = 0;
	num3 = 0;

	while (1)
	{
		printf("���ڸ� �Է����ּ���.");
		scanf("%d", &n);

		if (n == 0)	{
			printf("Program ����\n");
			break;
		}

        for (a = 1; a <= n; a++) {
				num3 = num1 + num2;
				num1 = num2;
				num2 = num3;
        }

        printf("%d ��° �Ǻ���ġ ���� %d�Դϴ�.\n\n", n, num3);

        num1 = 1;
        num2 = 0;
        num3 = 0;

	}

	return 0;
}
