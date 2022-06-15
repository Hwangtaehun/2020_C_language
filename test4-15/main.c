#include <stdio.h>
#include <stdlib.h>

int main() {
	float a = 0.0f, b = 1.0f, c = 0.0f;

	for (a = 1.0f; a <= 100.0f; a++) {
		b += 1;
		c += a / b;
	}
	printf("ÃÑÇÕÀº %f\n", c);

	return 0;
}
