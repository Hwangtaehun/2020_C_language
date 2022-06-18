#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() 
{
	int* pt, * pa, * pb;
	int i, cnt, temp;
	
	printf("배열 크기를 입력 : ");
	scanf("%d", &cnt);
	pt = new int[cnt];
	
	for (i = 0; i < cnt; i++) 
	{
		scanf("%d", pt + i);
	}

	for ( pa = pt; pa < pt + cnt - 1; pa++)
	{
		for ( pb = pa + 1; pb < pt + cnt; pb++)
		{
			if (*pa > *pb) 
			{
				temp = *pa;
				*pa = *pb;
				*pb = temp;
			}
		}
	}
	for (i = 0; i < cnt; i++)
		printf("%5d", pt[i]);
	putchar('\n');

	delete[]pt;

	return 0;
}