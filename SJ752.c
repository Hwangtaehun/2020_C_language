#include <stdio.h>

void sub();

int main(int argc, char **argv)
{
	sub();
	sub();
	sub();
	return 0;
}

void sub() 
{
	static int s = 10;
	auto int a = 10;
	s++;
	a++;
	printf("s = %d, a = %d \n", s, a);
}