//SJ637
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int** pp;
	int i, j, n = 0, m;
	printf("배열 크기를 입력 : ");
	scanf("%d", &m);
	pp = new int* [m];
	for ( i = 0; i < m; i++)
	{
		pp[i] = new int[m];
	}
	for ( i = 0; i < m; i++)
	{
		for (j = 0; j < m; j++) 
		{
			n++;
			pp[i][j] = n;
			printf("%5d", pp[i][j]);
		}
		printf("\n");
	}
	for ( i = 0; i < m; i++)
	{
		delete[] pp[i];
	}
	delete[]pp;
	return 0;
}