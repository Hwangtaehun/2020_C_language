#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	printf("세 과목을 입력해주세요?");
	scanf("%d %d %d", &a, &b, &c);

	if ( a >= 60 && b >= 60 && c >= 60)
	{
		printf("합격입니다.\n");
	}
	else
	{
		printf("불합격입니다.\n");
	}

	return 0;
}
