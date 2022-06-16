//SJ635
#include <stdio.h>
#include <string.h>

int main() 
{
	char temp[100] = "";
	char* pa, * pb;

	printf("첫 번째 문자열 입력 : ");
	scanf("%s", temp);
	pa = new char[strlen(temp) + 1];
	memcpy(pa, temp, strlen(temp) + 1);

	printf("두 번째 문자열 입력 : ");
	scanf("%s", temp);
	pb = new char[strlen(temp) + 1];
	memcpy(pb, temp, strlen(temp) + 1);

	printf("pa = %d 글자, %s\n", strlen(pa), pa);
	printf("pb = %d 글자, %s\n", strlen(pb), pb);

	return 0;
}