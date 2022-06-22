#include<stdio.h>

int my_strcmp(char* pstr1, char* pstr2);
void my_strcpy(char* pstr1, char* pstr2);
void my_strcat(char* pstr1, char* pstr2);

int main(void)
{
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	char str3[100] = { 0 };
	int n;

	printf("첫번째 문자열을 입력하세요\n");
	gets(str1);
	printf("두번째 문자열을 입력하세요\n");
	gets(str2);

	n = my_strcmp(str1, str2);
	printf("결과는 %d\n", n);

	my_strcpy(str1, str3);
	printf("복사 내용: %s\n", str3);

	my_strcat(str1, str2);
	printf("결합된 내용: %s\n", str1);

	return 0;
}

int my_strcmp(char* pstr1, char* pstr2) 
{
	int cnt1 = 0, cnt2 = 0;
	while (pstr1[cnt1] != NULL) 
	{
		cnt1++;
	}
	while (pstr2[cnt2] != NULL)
	{
		cnt2++;
	}

	if (cnt1 > cnt2)
		return 1;
	else if (cnt1 < cnt2)
		return -1;
	else
		return 0;
}

void my_strcpy(char* pstr1, char* pstr2)
{
	int cnt = 0;
	while(pstr1[cnt] != NULL)
	{
		pstr2[cnt] = pstr1[cnt];
		cnt++;
	}
}

void my_strcat(char* pstr1, char* pstr2) 
{
	int i, cnt1 = 0, cnt2 = 0;
	while (pstr1[cnt1] != NULL)
	{
		cnt1++;
	}
	while (pstr2[cnt2] != NULL)
	{
		cnt2++;
	}
	for (i = 0; i < cnt2; i++)
	{
		pstr1[cnt1 + i] = pstr2[i];
	}
}