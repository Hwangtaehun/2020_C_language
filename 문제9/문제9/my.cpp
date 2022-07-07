#include <stdio.h>

void Line(int cnt, char ch)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		putchar(ch);
	}
	putchar('\n');
}

void Spc(int cnt)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		putchar(' ');
	}
}