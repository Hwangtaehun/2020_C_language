#include <stdio.h>

int main() {
	int i, j;
	char sta[3][5] = { "abc", "defg", "hij" };

	printf("�� ���ھ� ����غ��ô�.\n");
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 5; j++)
		{
			printf("sta[%d][%d] = %c \n", i, j, sta[i][j]);
		}
	}

	printf("�� �྿ ����غ��ô�.\n");
	for (i = 0; i < 3; i++)
	{
		printf("sta[%d] = %s \n", i, sta[i]);
	}
	return 0;
}
