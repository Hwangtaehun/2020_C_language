#include <stdio.h>
void sub21();
void sub22();

void sub21()
{
	extern int data;

	data++;
	printf("sub21()����       data = %d \n", data);
	sub22();
}

void sub22()
{
	int data = 55;
	data ++;
	printf("sub22()����       data = %d \n", data);
}