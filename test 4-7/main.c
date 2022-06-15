#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c, avl;

	printf("세 과목을 입력해주세요?");
	scanf("%d %d %d", &a, &b, &c);

	avl = (a + b + c) / 3;

	if (avl >= 60 && a >= 40 && b >= 40 && c >= 40)
	{
		printf("합격입니다.\n");
	}
	else
	{
		printf("불합격입니다.\n");
	}

	return 0;
}
