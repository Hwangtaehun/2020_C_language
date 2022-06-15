#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0;
	float b = 0, c = 0;

	for (a = 1; a <= 100; a++)
	{
		b = a + 1;
		if (a % 2 == 0) {
			c -= a / b;
		}
		else {
			c += a / b;
		}
	}
	printf("ÃÑÇÕÀº %f\n", c);

	return 0;
}
