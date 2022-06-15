#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	for ( a = 65; a <= 90; a++)
	{
		for (b = a ; b <= 90; b++)
		{
			printf("%c", b);
		}

		for ( c = 65; c < a; c++)
		{
			printf("%c", c);
		}
		putchar('\n');
	}

	return 0;
}
