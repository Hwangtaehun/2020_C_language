#include <stdio.h>
#include <stdlib.h>

int main() {
	int a = 0, b = 0;

	do
	{
		a++;
		b += a;
	} while ( a < 100 );

	printf("гу = %d\n", b);
	return 0;
}
