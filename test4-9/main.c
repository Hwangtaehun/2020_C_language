#include <stdio.h>
#include <stdlib.h>

int main() {
	int year;

	printf("년도를 입력해주세요.\n");
	scanf("%d", &year);

	if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
	{
		printf("윤년입니다.\n");
	}

	else
	{
		printf("평년입니다.\n");
	}

	return 0;
}
