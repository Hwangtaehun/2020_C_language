#include <stdio.h>
#include <stdlib.h>

int main() {
	int a;

	printf("숫자를 입력해주세요.\n");
	a = getchar();

	if (a % 2 == 0 && a % 3 == 0)
	{
		printf("맞습니다.\n");
	}
	else
	{
		printf("틀립니다.\n");
	}

	return 0;
}
