#include <stdio.h>

void PrintStr(char** pt);

void main(int argc, char** argv)
{
	if (argc < 6)
	{
		printf("main�� �μ��� �����ϴ�.\n");
		return;
	}
	PrintStr(argv);
}

void PrintStr(char** pt)
{
	int i;
	for ( i = 0; i <= 5; i++)
	{
		printf("%s\n", pt[i]);
	}
}