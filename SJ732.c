#include <stdio.h>

void ArrayPrn1(int pt[]);
void ArrayPrn2(int pt[][4]);

int main(void) 
{
	int arr[3][4] = { {1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12 } };
	ArrayPrn1((int*)arr);
	ArrayPrn2(arr);
	return 0;
}

void ArrayPrn1(int pt[]) 
{
	int i;
	for ( i = 0; i < 12; i++)
	{
		printf("%3d", pt[i]);
	}
	putchar('\n');
}

void ArrayPrn2(int pt[][4]) 
{
	int i, j;
	for (i = 0; i < 3; i++)
	{
		for ( j = 0; j < 4; j++)
		{
			printf("%3d", pt[i][j]);
		}
		putchar('\n');
	}
}