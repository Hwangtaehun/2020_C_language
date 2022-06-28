#include <stdio.h>
void sub31();
void sub32();

extern int data;

void sub31()
{
	data++;
	printf("sub31()에서       data = %d \n", data);
	sub32();
}

void sub32()
{
	int data = 77;
	data++;
	printf("sub32()에서       data = %d \n", data);
	printf("sub32()에서     ::data = %d \n", data);
}