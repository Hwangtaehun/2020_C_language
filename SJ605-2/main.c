#include <stdio.h>
#include <stdlib.h>
#define MAX 10

int main()
{
    int arr[MAX+1] ={10, 8, 6, 4, 2, 9, 7, 5, 3, 1, 999};

    int i, temp;
    int *pa, *pb;

    printf(" sort 전의 배열 내용 : \t");
	for (i = 0; i < MAX; i++)
	{
		printf("%3d", *(arr+i));
	}
	printf("\n\n");

	for (pa = arr; pa < arr + MAX - 1; pa++)
	{
		for (pb = pa + 1; pb <arr+ MAX; pb++)
		{
			if (*pa < *pb)
			{
				temp = *pa;
				*pa = *pb;
				*pb = temp;
			}
		}
	}

	printf("\n sort 후의 배열 내용 : \t");
	for (pa = arr; pa < arr+MAX; pa++)
	{
		printf("%3d", *pa);
	}
	putchar('\n');

	pa=arr;
	printf("\n sort 후의 배열 내용 : \t");
	while(*pa != 999){
        printf("%3d", *pa);
        pa++;
	}
    printf("\n");
    return 0;
}
