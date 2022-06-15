#include <stdio.h>
#define MAX 5

int main() {
	int arr[MAX][MAX] = { 0 };
	int i = 0, n = 0;
	int (*pt)[MAX];
	int *pa;

	for (pt = arr; pt < arr + MAX; pt++)
	{
		for (pa = *pt; pa <= *pt + i; pa++)
		{
			n++;
			*pa = n;
		}
		i++;
	}

	for (pt = arr; pt < arr + MAX; pt++)
	{
		for (pa = *pt; pa < *pt + MAX; pa++)
		{
			if ( *pa == 0)
			{
				printf("   ");
			}
			else
			{
				printf("%3d", *pa);
			}
		}
		printf("\n");
	}
	return 0;
}
