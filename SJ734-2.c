#include<stdio.h>

int my_strlen1(char* pstr);
int my_strlen2(char* pstr);

int main(void) 
{
	char str[100];
	int n1, n2;

	printf("���ڿ��� �Է��ϼ���\n");
	gets(str);

	n1 = my_strlen1(str);
	n2 = my_strlen2(str);

	printf("�Էµ� ������ ������ %d ���Դϴ�.\n", n1);
	printf("�Էµ� ������ ������ %d ���Դϴ�.\n", n2);

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