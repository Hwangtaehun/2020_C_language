#include <stdio.h>
#include <string.h>

void PrintStr(char** pt);
void SortStr(char** pt);

void main(int argc, char** argv)
{
	if (argc < 6)
	{
		printf("main의 인수가 적습니다.\n");
		return;
	}
	printf("\nsort 전 ---------------\n");
	PrintStr(argv);

	SortStr(argv);
	printf("\nsort 후 ---------------\n");
	PrintStr(argv);
}

void PrintStr(char** pt)
{
	int i;
	for (i = 0; i <= 5; i++)
	{
		printf("%s\n", pt[i]);
	}
}

void SortStr(char** pt)
{
	int i, j;
	char* temp;
	for (i = 1; i < 4; i++)
	{
		for (j = i + 1; j < 5; j++)
		{
			if (strcmp(pt[i], pt[j]) > 0)
			{
				temp = pt[i];
				pt[i] = pt[j];
				pt[j] = temp;
			}
		}
	}
}