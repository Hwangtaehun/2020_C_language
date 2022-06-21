#include <stdio.h>

void Sub(int& num1, int& num2);

int main() {
	int a = 55, b = 33;

	printf("main에서 Sub()실행 전 : a = %d. b = %d\n", a, b);
	Sub(a, b);
	printf("main에서 Sub()실행 후 : a = %d. b = %d\n", a, b);
	return 0;
}

void Sub(int& num1, int& num2) {
	printf("Sub() 에서 : num1 = %d, num2 = %d\n", num1, num2);
	num1 = 111;
	num2 = 222; 
}