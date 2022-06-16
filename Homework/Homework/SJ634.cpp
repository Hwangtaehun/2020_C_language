//SJ634
#include <stdio.h>
#include <string.h>

int main() {
	char* pa, * pb;
	char temp[] = "Sejong Computer";

	printf("원래의    내용 : %s\n", temp);
	memset(temp, '*', 4);
	printf("* 대입 후 내용 : %s\n", temp);
	memset(temp, 65, 5);
	printf("A 대입 후 내용 : %s\n", temp);

	pa = new char[20];
	pb = new char[20];
	memset(pa, NULL, 20);
	memset(pa, 'A', 10);
	memset(pb, 'B', 10);
	printf("pa = %d, %s\n", strlen(pa), pa);
	printf("pb = %d, %s\n", strlen(pb), pb);

	strcpy(temp, "Sejong computer");
	printf("strcpy 실행 후 내용: %s\n", temp);
	memcpy(temp, "Sejong computer", 16);
	printf("memcpy 실행 후 내용: %s\n", temp);
	memcpy(pa, temp, 6);
	printf(" 6 Byte 복사 후 pa = %s\n", pa);

	return 0;
}