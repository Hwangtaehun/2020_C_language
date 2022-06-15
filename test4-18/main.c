#include <stdio.h>
#include <stdlib.h>

int main() {
	float a = 0, b = 1, f = 1;

	for ( a = 2; a <= 10; a++)
	{
		f = f * a;
		b += (a-1) / f;
	}

	printf("รัวี: %f", b);
	return 0;
}
