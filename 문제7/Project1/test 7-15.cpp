#include <stdio.h>
#include <string.h>

void PrintStr(char** pt);
void SortStr(char** pt);

void main(int argc, char** argv)
{
	if (argc < 6)
	{
		printf("main�� �μ��� �����ϴ�.\n");
		return;
	}
	printf("\nsort �� ---------------\n");
	PrintStr(argv);

	SortStr(argv);
	printf("\nsort �� ---------------\n");
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