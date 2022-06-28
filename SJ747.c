#include<stdio.h>

int sub1(int a, const int b);
char* my_strcpy(char* strDestination, const char* strSource);

int main(int argc, char** argv)
{
	char sta[100], stb[] = "Sejong Computer";
	char* pStr;
	int aa = 100, bb = 200, cc = 300;

	aa = sub1(bb, cc);
	printf("aa = %d \n", aa);
	pStr = my_strcpy(sta, stb);
	printf("sta = %s\nstb = %s\npStr = %s\n", sta, stb, pStr);
	sta[0] = 'A';
	printf("º¯°æ ÈÄ sta = %s\n", sta);
	return 0;
}

int sub1(int a, const int b)
{
	int c; 
	c = a + b;
	return c;
}

char* my_strcpy(char* strDestination, const char* strSource)
{
	char* strDest;
	const char* strSour;
	strSour = strSource;
	strDest = strDestination;

	while (*strSour != NULL)
	{
		*strDest = *strSour;
		strDest++;
		strSour++;
	}
	*strDest = NULL;
	return strDestination;
}