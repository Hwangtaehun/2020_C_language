#include <stdio.h>
#include "my.c"

int main(void) {
	int a;
	for (a = 1; a <= 5; a++) 
	{
		Spc(5 - a);
		Line(a, '*');
	}
	for ( a = 1; a <= 5; a++)
	{
		Spc(5 - a);
		Line(a * 2 - 1, '*');
	}
	for ( a = 4; a >= 1; a--)
	{
		Spc(5 - a);
		Line(a * 2 - 1, '*');
	}

	return 0;
}