#include <stdio.h>

void Swap(int num1, int num2);

int main() {
	int a = 55, b = 33;
	printf("main���� Swap()���� �� : a = %d. b = %d\n", a, b);
	Swap(a, b);
	printf("main���� Swap()���� �� : a = %d. b = %d\n", a, b);
	return 0;
}

void Swap(int num1, int num2) 
{
	int temp;
	printf("Swap���� ��ȯ ��: num1 = %d, num2 = %d\n", num1, num2);

	temp = num1;
	num1 = num2;
	num2 = temp;

	printf("Swap���� ��ȯ ��: num1 = %d, num2 = %d\n", num1, num2);

}