#include <stdio.h>
#define ACNT 6
#define BCNT 4
#define CCNT 10

int main() {
	int aa[ACNT] = { 11,44,55,77,98,99 };
	int bb[BCNT] = { 22,33,66,88 };
	int cc[CCNT] = { 0 };
	int ia, ib, ic, i;

	ia = ib = ic = 0;
	do {
		if (aa[ia] < bb[ib]) {
			cc[ic] = aa[ia];
			ia++;
		}

		else
		{
			cc[ic] = bb[ib];
			ib++;
		}
		ic++;
	} while (ia < ACNT && ib < BCNT);

	if (ia >= ACNT)
	{
		for (i = ib; i < BCNT; i++)
		{
			cc[ic] = bb[i];
			ic++;
		}
	}
	else
	{
		for (i = ia; i < ACNT; i++)
		{
			cc[ic] = aa[i];
			ic++;
		}
	}

	printf("배열 내용 : \t");
	for ( i = 0; i < CCNT; i++)
	{
		printf("%3d", cc[i]);
	}
	printf("\n\n");

	return 0;
}
