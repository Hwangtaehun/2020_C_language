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
	printf("main()���� staticData = %d\n", g_staticData);
	sub11();
	sub12();
	sub21();
	sub31();
	printf("main���� sub 32 ȣ��\n");
	sub32();
	return 0;
}

void sub11()
{
	data++;
	printf("sub11()���� data = %d \n", data);
}

void sub12()
{
	int data = 33;
	data++;
	printf("sub12()����       data = %d (��������)\n", data);
	printf("sub12()����     ::data = %d (��������)\n", ::data);
	printf("sub12()���� staticData = %d \n", g_staticData);
}
