#include <stdio.h>

void Alphabet(char startChar, char endChar);
void Alphabet2(char startChar, char endChar);
void GuGuDan(int dan);
void Line(int cnt, char ch);
void Spc(int cnt);

int main(void) {
	int i;
	char ch;

	for ( ch = 'A'; ch <= 'Z'; ch++)
	{
		Alphabet('A', 'Z');
	}
	putchar('\n');

	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		Alphabet(ch, 'Z');
	}
	putchar('\n');

	for ( i = 0; i < 26; i++)
	{
		Spc(25 - i);
		Alphabet('A', 'A' + i);
	}
	putchar('\n');

	for (i = 0; i < 13; i++)
	{
		Spc(12 - i);
		Alphabet('A', 'A' + i * 2);
	}
	putchar('\n');

	for (ch = 'A'; ch <= 'Z'; ch++)
	{
		Alphabet2(ch, 'Z');
		Alphabet('A', ch - 1);
	}
	putchar('\n');

	for (i = 1; i <= 9; i++)
	{
		GuGuDan(i);
	}
	putchar('\n');

	return 0;
}

void Alphabet(char startChar, char endChar) 
{
	char ch;
	for ( ch = startChar; ch <= endChar; ch++)
	{
		putchar(ch);
	}
	putchar('\n');
}

void Alphabet2(char startChar, char endChar)
{
	char ch;
	for (ch = startChar; ch <= endChar; ch++)
	{
		putchar(ch);
	}
}

void GuGuDan(int dan) {
	int i;
	for ( i = 1; i <= 9; i++)
	{
		printf("%d*%d=%2d ", dan, i, dan * i);
	}
	putchar('\n');
}