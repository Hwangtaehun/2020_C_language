#include<stdio.h>

int my_strlen1(char* pstr);
int my_strlen2(char* pstr);

int main(void) 
{
	char str[100];
	int n1, n2;

	printf("문자열을 입력하세요\n");
	gets(str);

	n1 = my_strlen1(str);
	n2 = my_strlen2(str);

	printf("입력된 문자의 갯수는 %d 개입니다.\n", n1);
	printf("입력된 문자의 갯수는 %d 개입니다.\n", n2);

	return 0;
}

int my_strlen1(char* pstr) 
{
	int cnt = 0;
	while(pstr[cnt] != NULL)
	{
		cnt++;
	}
	return cnt;
}

int my_strlen2(char* pstr)
{
	int cnt = 0;
	while (*pstr != NULL)
	{
		cnt++;
		pstr++;
	}
	return cnt;
}