//Sj714
#include<stdio.h>
#define NAME "(林)技辆"
#define ADDR "面合 没林矫 蕊傣备 荤流1悼"
#define TEL "043-274-4111"

void Line(int cnt, char ch);
void Spc(int cnt);

int main(void) {
	Line(60, '=');
	Spc((60 - strlen(ADDR)) / 2);
	printf("%s\n", ADDR);
	Spc((60 - strlen(NAME)) / 2);
	printf("%s\n", NAME);
	Spc((60 - strlen(TEL)) / 2);
	printf("%s\n", TEL);
	Line(60, '-');
	return 0;
}

void Line(int cnt, char ch) 
{
	int i;
	for ( i = 0; i <= cnt; i++)
	{
		putchar(ch);
	}
	putchar('\n');
}

void Spc(int cnt) 
{
	int i;
	for ( i = 0; i < cnt; i++)
	{
		putchar(' ');
	}
}