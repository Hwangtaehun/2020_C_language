#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, ten, one, fin;
	int cnt = 0;

	scanf("%d", &a);

	ten = a / 10;
	one = a % 10;


		while (ten != 0)
		{
			fin = ten * one;
			ten = fin / 10;
			one = fin % 10;
			cnt++;
		}

		if (cnt >= 4)
		{
			printf("�ݺ�Ƚ���� %dȸ �̹Ƿ� ������\n", cnt);

		}
		else
		{
			printf("�ݺ�Ƚ���� %dȸ �̹Ƿ� ������\n", cnt);

		}

	return 0;
}
