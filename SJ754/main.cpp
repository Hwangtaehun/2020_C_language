#include <stdio.h>
#include "SJ754-2.h"
#include "SJ754-3.h"

void sub11();
void sub12();
void sub21();
void sub31();
void sub32();

int data;
static int g_staticData;

int main(int argcc, char **argv)
{
	data = 11;
	g_staticData = 333;
	printf("main()에서 staticData = %d\n", g_staticData);
	sub11();
	sub12();
	sub21();
	sub31();
	printf("main에서 sub 32 호출\n");
	sub32();
	return 0;
}

void sub11()
{
	data++;
	printf("sub11()에서 data = %d \n", data);
}

void sub12()
{
	int data = 33;
	data++;
	printf("sub12()에서       data = %d (지역변수)\n", data);
	printf("sub12()에서     ::data = %d (전역변수)\n", ::data);
	printf("sub12()에서 staticData = %d \n", g_staticData);
}
