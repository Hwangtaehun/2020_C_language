#include<stdio.h>

int main(int argc, char **argv)
{
	int a = 100, b = 200;
	printf("ù��°  a = %d, b = %d, &a = %u\n", a, b, &a);
	{
		int a = 300;
		printf("�ι�°  a = %d, b = %d, &a = %u\n", a, b, &a);
		{
			int a = 500;
			printf("����°  a = %d, b = %d, &a = %u\n", a, b, &a);
		}
		printf("�׹�°  a = %d, b = %d, &a = %u\n", a, b, &a);
	}
	printf("�ټ���° a = %d, b = %d, &a = %u\n", a, b, &a);
	return 0;
}