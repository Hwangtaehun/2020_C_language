#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

void MyUpper(char *str);
void MyLower(char str[]);

void main(void)
{
	char str[100];
	while (1)
	{
		printf("문자열을 입력하세요. ( 종료는 ^Z ) ==> ");
		if (scanf("%s", str) == EOF)
			break;
		MyUpper(str);
		printf("대문자로 변환 후 : %s \n", str);
		MyLower(str);
		printf("소문자로 변환 후 : %s \n", str);
	}
}

void MyUpper(char *str)
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] -= ('a' - 'A');
		i++;
	}
}

void MyLower(char str[])
{
	int i = 0;
	while (str[i] != NULL)
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
		i++;
	}
}