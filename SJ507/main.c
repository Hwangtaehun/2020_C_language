#include <stdio.h>

int main() {
	int i, j;
	char sta[3][5] = { "abc", "defg", "hij" };

	printf("한 문자씩 출력해본시다.\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("sta[%d][%d] = %c \n", i, j, sta[i][j]);
		}
	}

	printf("한 행씩 출력해봅시다.\n");
	for (i = 0; i < 3; i++)
	{
		printf("sta[%d] = %s \n", i, sta[i]);
	}
	return 0;
}
