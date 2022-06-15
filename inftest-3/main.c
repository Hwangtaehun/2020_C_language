#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 78, i = 0, b=0;

	for (i = 1; i <= 77; i++)
	{
		b += (a - i) * i;
	}

	printf("ÃÑÇÕÀº %d", b);
	return 0;
}
