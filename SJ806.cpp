#include <stdio.h>

enum TEST {AA, BB = 5, CC, DD = 3, EE};
enum DIRECTION {EAST, WEST, SOUTH, NORTH};
typedef enum bool_tag { FALSE = 0, TRUE = 1} BOOL;

int main(int argc, char** argv)
{
	int i;
	BOOL bb;
	enum DIRECTION dd;
	enum TEST tt;

	tt = BB;
	printf(" tt = %d\n", tt);

	printf(" AA  BB  CC  DD  EE \n");
	printf("%3d %3d %3d %3d %3d \n", AA, BB, CC, DD, EE);
	printf("AA���� DD ���� ��� : ");
	for ( i = AA; i <= DD; i++)
	{
		printf(" %3d", i);
	}
	printf("\n");

	dd = SOUTH;
	switch (dd)
	{
	case EAST:
		printf("�����Դϴ�.\n");
		break;
	case WEST:
		printf("�����Դϴ�.\n");
		break;
	case SOUTH:
		printf("�����Դϴ�.\n");
		break;
	case NORTH:
		printf("�����Դϴ�.\n");
		break;
	}
	printf("\n");
	bb = TRUE;
	if (bb)
		printf("bb = TURE �Դϴ�.\n");
	else
		printf("bb = FALSE �Դϴ�.\n");
	return 0;
}