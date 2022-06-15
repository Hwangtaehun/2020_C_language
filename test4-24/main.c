#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	for (a = 1; a <= 9; a++)
	{
		for (b = 1; b <= 9; b++)
		{
			printf("%d * %d = %2d ", a, b, a * b);
		}
		putchar('\n');
	}

	return 0;
}
