#include <stdio.h>
#include <stdlib.h>

int main() {
	int n = 0;
	char ch;
	for ( ch = '#'; ch <= '}'; ch++)
	{
		putchar(ch);
		if (ch % 7 == 6) {
			putchar('\n');
		}
	}
	putchar('\n');
	return 0;
}
