#include <stdio.h>

struct ST {
	char a;
	short int b;
	long c;
};

union UN {
	char a;
	short int b;
	long c;
};

int main(int argc, char** argv)
{
	ST ss;
	UN uu;
	ss.c = uu.c = 0x12345678;
	ss.b = uu.b = (short int)0xABCD;
	ss.a = uu.a = (char)0xEF;

	printf("ss = %X, %X, %X \n", ss.a, ss.b, ss.c);
	printf("uu = %X, %X, %X \n", uu.a, uu.b, uu.c);
	printf("sizeof(ss) = %d \n", sizeof(ss));
	printf("sizeof(uu) = %d \n", sizeof(uu));
	printf("ss member의 번지 %u, %u, %u\n", &ss.a, &ss.b, &ss.c);
	printf("uu member의 번지 %u, %u, %u\n", &uu.a, &uu.b, &uu.c);

	union
	{
		int i;
		char c[4];
	};
	i = 0x12345678;
	printf("i = %X \n", i);
	for (int j = 0; j < 4; j++)
	{
		printf("c[%d] = %X\n", j, c[j]);
	}
	printf("&i = %u, c = %u\n", &i, c);
	return 0;
}