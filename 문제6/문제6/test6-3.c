#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char str[] = "Sejong";
	char* pt;
	pt = str;
	
	while (*pt != NULL) 
	{
		printf("%s\n", pt);
		pt++;
	}
	putchar('\n');
	
	return 0;
}