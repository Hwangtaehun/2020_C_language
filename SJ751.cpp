#include <stdio.h>

void aplus();
int bplus(int n1, int n2);
void sub();

int x, y, z;

int main(int argc, char** argv) 
{
	int a, b, c;
	a = x = 11;
	b = y = 22;
	aplus();
	c = bplus(a, b);
	printf("z = %d\n", z);
	printf("c = %d\n", c);
	sub();
	return 0;
}

void aplus()
{
	z = x + y;
}

int bplus(int n1, int n2)
{
	return (n1 + n2);
}

void sub()
{
	int x = 555;
	printf("지역 변수   x = %d\n", x);
	printf("전역 변수 ::x = %d\n", ::x);
}