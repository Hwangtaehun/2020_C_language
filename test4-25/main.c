#include <stdio.h>
#include <stdlib.h>

int main() {
	int a, b, c;

	printf("           \t구 구 단\n");
	printf("			작성자 : 세종 정보\n");
	for (a = 1; a <= 9; a += 3)
	{
		printf("  제 %d 단\t  제 %d 단\t  제 %d 단\n", a, a+1, a+2);
		for (b = 1; b <= 9; b++)
		{
				printf("%d * %d = %2d\t", a, b, a * b);
				printf("%d * %d = %2d\t", a + 1, b, (a + 1) * b);
				printf("%d * %d = %2d\n", a + 2, b, (a + 2) * b);
		}
	}

	return 0;
}
