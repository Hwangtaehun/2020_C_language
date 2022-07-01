#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int NumberCount(int pt[], int* pnum);

#define MAX 100

void main(void)
{
	int i, cnt, num, arr[MAX];
	srand((unsigned)time(NULL));
	for ( i = 0; i < MAX; i++)
	{
		arr[i] = rand() % MAX;
	}
	printf("발생된 수 \n");
	for (i = 0; i < MAX; i++)
	{
		printf("%5d", arr[i]);
		if (i % 10 == 9)
			printf("\n");
	}
	printf("\n");
	cnt = NumberCount(arr, &num);
	printf("가장 많이 발생된 수 = %d, 횟수 = %d \n", num, cnt);
}

int NumberCount(int pt[], int* pnum)
{
	int i, max = 0, maxnum, numcnt[MAX] = { 0 };
	for (i = 0; i < MAX; i++)
		numcnt[pt[i]]++;
	for (i = 0; i < MAX; i++)
	{
		if (max < numcnt[i])
		{
			max = numcnt[i];
			maxnum = i;
		}
	}
	*pnum = maxnum;
	return max;
}