//SJ633
#include <stdio.h>

int main() {
	char* cpt;
	char** pp;
	int i;
	cpt = new char[100];

	printf("���ڿ��� �Է� : ");
	scanf("%s", cpt);
	printf("%p, %s\n", cpt, cpt);

	pp = new char* [3];
	pp[0] = cpt;
	pp[1] = "mbc";
	pp[2] = "cjb";
	for (i = 0; i < 3; i++) 
	{
		printf("pp[%d] = %s\n", i, pp[i]);
	}
	delete[]cpt;
	delete[]pp;
	return 0;
}