#include <stdio.h>
void sub21();
void sub22();

void sub21()
{
	extern int data;
	extern int g_staticData;

	// g_staticData++;
	data++;
	printf("sub21()에서       data = %d \n", data);
	sub22();
}

void sub22()
{
	int data = 55;
	data ++;
	printf("sub22()에서       data = %d \n", data);
}
