#include <stdio.h>
#define D1 11
#define D2 22
#define D3 33

const int C1 = 11, C2 = 22, C3 = 33;
int main(int argc, char**argv)
{
	printf("D1 = %d, C1 = %d\n", D1, C1);
	printf("D1 = %d, C1 = %d\n", D2, C2);
	printf("D1 = %d, C1 = %d\n", D3, C3);

	printf("%u, %u\n", &C1, &C2);
	return 0;
}