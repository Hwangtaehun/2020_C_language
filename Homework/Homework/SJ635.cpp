//SJ635
#include <stdio.h>
#include <string.h>

int main() 
{
	char temp[100] = "";
	char* pa, * pb;

	printf("ù ��° ���ڿ� �Է� : ");
	scanf("%s", temp);
	pa = new char[strlen(temp) + 1];
	memcpy(pa, temp, strlen(temp) + 1);

	printf("�� ��° ���ڿ� �Է� : ");
	scanf("%s", temp);
	pb = new char[strlen(temp) + 1];
	memcpy(pb, temp, strlen(temp) + 1);

	printf("pa = %d ����, %s\n", strlen(pa), pa);
	printf("pb = %d ����, %s\n", strlen(pb), pb);

	return 0;
}