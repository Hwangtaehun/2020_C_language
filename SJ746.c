#include<stdio.h>

int main(int argc, char **argv)
{
	int aa = 100, bb = 220, cc = 300, dd = 400;
	int* pa;
	pa = &bb;
	pa = &aa;
	*pa = 111;
	printf("aa = %d, *pa = %d \n", aa, *pa);

	const int* pb;
	pb = &aa;
	pb = &bb;
	bb = 222;
	printf("bb = %d, *pb = %d \n", bb, *pb);

	int* const pc = &cc;
	*pc = 333;
	printf("cc = %d, *pc = %d \n", cc, *pc);

	const int* const pd = &dd;
	printf("cc = %d, *pc = %d \n", dd, *pd);

	return 0;
}