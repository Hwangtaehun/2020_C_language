#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n, r, f, p, c;
	printf("n r �Է�: ");
	scanf("%d %d", &n, &f);

	f = 1;

	for ( i = 1; i <= n; i++)
	{
		f = f * i;
	}
	printf("%d! = %d(%d���� ��Ҹ� �����ϴ� ����� ��)\n", n, f, n);
}
