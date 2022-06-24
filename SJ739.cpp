#include <stdio.h>

void Sub();
void Sub(int x);
void Sub(int x, int y);
void Sub(double x, double y);
void Sub(float x, float y);

int main()
{
	Sub();
	Sub(11);
	Sub(11, 22);
	Sub(11.1, 22.2);
	Sub(333.3f, 444.4f);
	return 0;
}

void Sub()
{
	printf("Sub() »£√‚µ \n");
}

void Sub(int x)
{
	printf("Sub(int x) »£√‚µ  x = %d \n", x);
}

void Sub(int x, int y)
{
	printf("Sub(int x, int y) »£√‚µ  x = %d y = %d \n", x, y);
}

void Sub(double x, double y)
{
	printf("Sub(double x, double y) »£√‚µ  x = %6.2lf y = %6.2lf \n", x, y);
}

void Sub(float x, float y)
{
	printf("Sub(float x, float y) »£√‚µ  x = %6.2f y = %6.2f \n", x, y);
}