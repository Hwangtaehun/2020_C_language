#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>

struct LIST
{
	char name[10];
	char addr[20];
	int link;
};

int main(int argc, char** argv)
{
	struct LIST *pa;
	struct LIST *pb;
	strcpy(pa->name, "¿Õ°Ç");
	strcpy(pa->addr, "¼Û¾Ç");
	pa->link = NULL;
	strcpy(pb->name, "°ßÈØ");
	strcpy(pb->addr, "¹«ÁøÁÖ");
	pb->link = NULL;
	pa->link = pb;

	printf(" pa->name = %s, pa->addr = %s\n", pa->name, pa->addr);
	printf(" pb->name = %s, pb->addr = %s\n", pb->name, pb->addr);
	printf(" pa->link->name = %s\n", pa->link->name);
	printf(" pa->link->addr = %s\n", pa->link->addr);

	return 0;
}