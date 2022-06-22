#include <stdio.h>
#include <string.h>

void StrPrn1(char** pt);
void StrPrn2(char* pt[]);
void StrSort(char** pt);

int main(void)
{
	char* pstr[6] = { "visual-c++", "java", "php", "basic", "turbo-c" };
	printf("\n정렬 전 내용\n");
	StrPrn1(pstr);
	StrSort(pstr);
	printf("\n정렬 후 내용\n");
	StrPrn2(pstr);

	return 0;
}

void StrPrn1(char** pt)
{
	while(*pt != NULL)
	{
		printf("%s\n", *pt);
		pt++;
	}
}

void StrPrn2(char* pt[])
{
	int i;
	for ( i = 0; i < 5; i++)
	{
		printf("%s\n", pt[i]);
	}
}

void StrSort(char** pt)
{
	char* temp;
	int i, j;
	for ( i = 0; i < 4; i++)
	{
		for ( j = i+1; j < 5; j++)
		{
			if (strcmp(pt[i],pt[j]) > 0)
			{
				temp = pt[i];
				pt[i] = pt[j];
				pt[j] = temp;
			}
		}
	}
}