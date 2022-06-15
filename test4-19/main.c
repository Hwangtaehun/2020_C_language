#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0;

	for ( a = 1; a <= 100; a++)
	{
		b += a;

		if (a % 10 == 0)
		{
			printf("1~%d±îÁö ÇÕ = %d\n", a, b);
		}
	}

	return 0;
}
