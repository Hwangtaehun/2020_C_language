#include <stdio.h>

void ArrayInput(int k[][3]);
void ArrayPrn(int k[][3]);

int main() {
	int k[3][3];
	ArrayInput(k);
	ArrayPrn(k);

	return 0;
}

void ArrayInput(int k[][3])
{
    int i, j, cnt = 0;

	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			cnt++;
			k[i][j] = cnt;
		}
	}

}

void ArrayPrn(int k[][3])
{
    int i, j;
    printf(" 배열에 입력된 내용 출력 \n");
    for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%5d", k[i][j]);
		}
		printf("\n");
	}
}
