#include <stdio.h>
#include <stdlib.h>

int main() {
	int age;

	printf("���̸� �Է����ּ���.\n");
	scanf("%d", &age);

	if (age >= 10 && age < 20)
		printf("10��\n");
	else if (age >= 20 && age < 30)
		printf("20��\n");
	else if (age >= 30 && age < 40)
		printf("30��\n");
	else
		printf("��Ÿ\n");

	return 0;
}
