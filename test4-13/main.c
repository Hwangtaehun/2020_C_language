#include <stdio.h>
#include <stdlib.h>

int main() {
	char c;

	printf("하나의 문자를 입력해주세요.");
	c = getchar();

	switch (c)
	{
	case'I':
	case'i':
		printf("삽입을 선택하셨습니다.\n");
		break;
	case'M':
	case'm':
		printf("수정을 선택하셨습니다.\n");
		break;
	case'D':
	case'd':
		printf("삭제를 선택하셨습니다.\n");
		break;
	default:
		printf("잘못 입력하였습니다.\n");
	}

	return 0;
}
