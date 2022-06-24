#include <stdio.h>

void Sub(int x = 100, int y = 200, int z = 300);
void Sub1(int a, int b = 100);

int main() 
{
	Sub();
	Sub(11);
	Sub(11, 22);
	Sub(11, 22, 33);

	Sub1(11);
	return 0;
}

void Sub(int x, int y, int z)
{
	printf("x=%3d, y=%3d, z=%3d \n", x, y, z);
}

void Sub1(int a, int b)
{
	printf("a=%3d, b = %3d\n", a, b);
}