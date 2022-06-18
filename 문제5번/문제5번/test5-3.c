#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char str[50];
	int i, j, cnt;
	while (1)
	{
		printf("문자열 입력(종료 ^Z) : ");
		if (scanf("%s", str) == EOF)
			break;
		cnt = 0;
		while (str[cnt] != NULL)
			cnt++;
		for (i = 0; i < cnt; i++)
		{
			for (j = 0; j < cnt - i - 1; j++) 
			{
				putchar(' ');
			}
			for (j = 0; j <= i; j++) 
			{
				putchar(str[j]);
			}
			for (j = i - 1; j > 0; j--) 
			{
				putchar(str[j]);
			}
			putchar('\n');
		}
	}
}