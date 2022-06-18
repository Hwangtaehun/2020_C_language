#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX 8

int main() 
{
	char num1[MAX], num2[MAX], num3[MAX + 5];
	int i, temp, n1, n2, n3, carry, comma;
	
	while (1)
	{
		printf("계산할 값 2개 입력(최대%d자리, 종료 ^Z) : ", MAX - 1);
		if (scanf("%s %s", num1, num2) == EOF)
			break;

		n1 = n2 = 0;
		while (num1[n1] != NULL)
			n1++;
		while (num2[n2] != NULL)
			n2++;

		n3 = MAX + 4;
		num3[n3] = NULL;
		carry = comma = 0;

		while (1)
		{
			n1--, n2--, n3--;
			if (n1 < 0 || n2 < 0)
				break;
			temp = (num1[n1] - '0') + (num2[n2] - '0') + carry;
			num3[n3] = temp % 10 + '0';
			carry = temp / 10;
		}
		while (n1 >= 0)
		{
			temp = num1[n1] - '0' + carry;
			num3[n3] = temp % 10 + '0';
			carry = temp / 10;
			n1--, n3--;
		}
		while (n2 >= 0)
		{
			temp = num2[n2] - '0' + carry;
			num3[n3] = temp % 10 + '0';
			carry = temp / 10;
			n2--, n3--;
		}
		if (carry > 0) 
		{
			num3[n3] = carry + '0';
			n3--;
		}
		for (i = n3 + 1; i < 12; i++)
		{
			if (i % 3 == 0 && i != (n3 + 1))
				printf(",");
			printf("%c", num3[i]);
		}
		putchar('\n');
	}
	return 0;
}