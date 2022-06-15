#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0;
	float b = 0, c = 0;

	for (a = 1; a <= 10; a++)
	{
		if (a % 2 == 0) {
			b += a;
			c += a / b;
		}
		else {
			b += a;
			c -= a / b;
		}
	}

	printf("ÃÑÇÕÀº %f", c);
	return 0;
}
