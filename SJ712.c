//SJ712
#include<stdio.h>

void Sub1(int val);
void Sub2(int val1, int val2);

int main(void) {
	printf("���α׷� ����\n");
	Sub1(33);

	Sub2(55, 77 + 11);

	printf("���α׷� ��\n");
	return 0;
}

void Sub1(int val) {
	printf("Sub1�� ���޵� ���� %5d\n", val);
}

void Sub2(int val1, int val2) {
	printf("sub2�� ���޵� ���� %5d, %5d\n", val1, val2);
}