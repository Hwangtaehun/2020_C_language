#include <stdio.h>
#include <stdlib.h>

int main() {
	float a=0, b=0;

	for (a = 1; a <= 100; a++)
	{
		b += 1 / a;
	}
	printf("ÃÑÇÕÀº %f\n", b);

	return 0;
}
