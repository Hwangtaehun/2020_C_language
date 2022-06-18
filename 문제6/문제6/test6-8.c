#include <stdio.h>

int main() 
{
	char* pt[3];
	int i;
	pt[0] = "sejong";
	pt[1] = "computer";
	pt[2] = "academy";

	for ( i = 0; i < 3; i++)
	{
		printf("%s\n", pt[i]);
	}

	return 0;
}