#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int i, n, r, f, p, c;
	printf("n r 입력: ");
	scanf("%d %d", &n, &f);

	f = 1;

	for ( i = 1; i <= n; i++)
	{
		f = f * i;
	}
	printf("%d! = %d(%d개의 요소를 나열하는 경우의 수)\n", n, f, n);
}
