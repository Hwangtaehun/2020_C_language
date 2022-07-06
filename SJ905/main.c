#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	FILE* inf;
	char str[80];
	int cnt = 0;

	if ((inf = fopen("..\\sejong.txt", "rt")) == EOF)
	{
		printf("file open error \n");
		exit(0);
	}

	while ((fgets(str, 80, inf)) != NULL)
	{
		printf("%3d : ", ++cnt);
		fputs(str, stdout);
	}

	fclose(inf);
	return 0;
}
