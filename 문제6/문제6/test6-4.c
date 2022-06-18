#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	char str1[10] = "computer", str2[10];
	char* pt1, * pt2;
	pt1 = str1;
	pt2 = str2;

	while (*pt1 != NULL) 
	{
		*pt2 = *pt1 - ('a' - 'A');
		pt1++;
		pt2++;
	}
	*pt2 = NULL;
	printf("%s\n", str2);

	return 0;
}