#include <stdio.h>
#include <stdlib.h>

int main() {
	int age;

	printf("나이를 입력해주세요.\n");
	scanf("%d", &age);

	if (age >= 10 && age < 20)
		printf("10대\n");
	else if (age >= 20 && age < 30)
		printf("20대\n");
	else if (age >= 30 && age < 40)
		printf("30대\n");
	else
		printf("기타\n");

	return 0;
}
