#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
void Dan(int n);

int main()
{
	int n;
	while (1)
	{
		printf("출력할 구구단(2-9, 0:종료) : ");
		scanf("%d", &n);
		if (n == 0)
			break;

		if(n <2 || n>9)
		{
			printf("2 - 9 사이의 수를 입력하세요.\n");
			continue;
		}
		Dan(n);
	}
	return 0;
}

void Dan(int n)
{
	int i;
	printf("------------\n");
	printf(" 제 %d 단 \n", n);
	printf("------------\n");
	for (i = 0; i <= 9; i++)
	{
		printf("%d * %d = %2d\n", n, i, n * i);
	}
	printf("------------\n");
}