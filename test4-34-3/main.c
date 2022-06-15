#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, bak, ten, one, fin;


	printf("세자리 수 입력해주세요.\n");
	scanf("%d", &a);

	if (a >= 100)
	{
		bak = a / 100;
		ten = a / 10 - a / 100 * 10;
		one = a % 10;

		fin = bak * bak * bak + ten * ten * ten + one * one * one;

		if (a == fin)
			printf("나르시스트 입니다.\n");
		else
			printf("나르시스트가 아닙니다.\n");
	}
	else
		printf("세자리 수 아닙니다.\n");


	return 0;
}
