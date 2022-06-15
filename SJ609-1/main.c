#include <stdio.h>

int main() {
	int arr[3][3];
	int i, j, cnt = 0;
	int (*pt)[3];
	int *pa;

	pt = arr;
	for ( i = 0; i < 3; i++)
	{
		for ( j = 0; j < 3; j++)
		{
			cnt++;
			//pt[i][j] = cnt;
			//(*(pt+i))[j] = cnt;
			*(*(pt+i)+j) = cnt;
		}
	}

	printf(" 배열에 입력된 내용 출력 1\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			//printf("%5d", *( (int *)pt+j) );
			printf("%5d", *( *pt+j) );
		}
		pt++;
		printf("\n");
	}

	pa = (int *)arr;
	printf(" 배열에 입력된 내용 출력 2\n");
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			printf("%5d", *pa );
            pa++;
		}
		printf("\n");
	}
	return 0;
}
