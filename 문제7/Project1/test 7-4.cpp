#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void StrOut(char ss[]);

void main()
{
	char str[100];
	while (1)
	{
		printf("문자열 입력 (^z : 종료) : ");
		if (scanf("%s", str) == EOF)
			break;
		StrOut(str);
	}
}

void StrOut(char ss[])
{
	while (*ss != NULL)
	{
		putchar(*ss);
		ss++;
	}
	putchar('\n');
}