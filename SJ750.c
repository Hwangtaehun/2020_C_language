#include<stdio.h>

int main(int argc, char **argv)
{
	int a = 100, b = 200;
	printf("첫번째  a = %d, b = %d, &a = %u\n", a, b, &a);
	{
		int a = 300;
		printf("두번째  a = %d, b = %d, &a = %u\n", a, b, &a);
		{
			int a = 500;
			printf("세번째  a = %d, b = %d, &a = %u\n", a, b, &a);
		}
		printf("네번째  a = %d, b = %d, &a = %u\n", a, b, &a);
	}
	printf("다섯번째 a = %d, b = %d, &a = %u\n", a, b, &a);
	return 0;
}