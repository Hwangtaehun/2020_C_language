#include <stdio.h>
#include <stdlib.h>

int main()
{
	int a, b;

	for ( a = 65; a <= 77; a++)
	{
		for ( b = 1;  b <= 77 - a ;  b++)
		{
			putchar(' ');
		}
		for ( b = 65; b <= 2 * a - 65; b++)
		{
			printf("%c", b);
		}
		putchar('\n');
	}

	return 0;
}
