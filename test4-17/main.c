#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0, f = 1;

	for (a = 1; a <= 10; a++)
	{
		f = f * a;
		b += f;
	}

	printf("รัวี: %d", b);
	return 0;
}
