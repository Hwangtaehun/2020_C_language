#include <stdio.h>
#include <stdlib.h>

int main() {
	float a = 0, b = 0, c = 0;

	for ( a = 1; a <= 10; a++)
	{
		b += a;
		c += a / b;
	}

	printf("ÃÑÇÕÀº %f", c);
	return 0;
}
