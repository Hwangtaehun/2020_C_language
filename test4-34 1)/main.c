#include <stdio.h>
#include <stdlib.h>

int main() {
	int num1, num2, num3, n, a;
	num1 = 1;
	num2 = 0;

	printf("숫자를 입력해주세요.");
	scanf("%d", &n);

	for (a = 1; a <= n; a++) {
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
	}

	printf("%d 번째 피보나치 수는 %d입니다.\n", n, num3);

	return 0;
}
