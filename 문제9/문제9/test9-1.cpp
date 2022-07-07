#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void ReadFile(FILE* fp);
void WriteFile(FILE* fp);

int main(void)
{
	FILE* fp;

	if ((fp = fopen("sungjuk.dat", "w")) == NULL)
	{
		printf(" ��� File open error\n");
		exit(0);
	}
	WriteFile(fp);
	fclose(fp);

	if((fp = fopen("sungjuk.dat", "r")) == NULL)
	ReadFile(fp);
	fclose(fp);

	return 0;
}

void ReadFile(FILE* fp)
{
	char name[10];
	int age, score;
	printf("\n\n");
	while (fscanf(fp, "%s%d%d", name, &age, &score) != EOF)
	{
		printf("%s���� ���̴� %d ������ %d �Դϴ�.\n", name, age, score);
	}
}

void WriteFile(FILE* fp)
{
	char name[10];
	int age, score;
	printf("\n�̸� ���� ���� �Է� ����� ^Z\n");
	while (scanf("%s%d%d", name, &age, &score) != EOF)
	{
		fprintf(fp, "%-8s%3d%3d\n", name, age, score);
	}
}