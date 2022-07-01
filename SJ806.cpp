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
	printf("AA부터 DD 까지 출력 : ");
	for ( i = AA; i <= DD; i++)
	{
		printf(" %3d", i);
	}
	printf("\n");

	dd = SOUTH;
	switch (dd)
	{
	case EAST:
		printf("동쪽입니다.\n");
		break;
	case WEST:
		printf("서쪽입니다.\n");
		break;
	case SOUTH:
		printf("남쪽입니다.\n");
		break;
	case NORTH:
		printf("북쪽입니다.\n");
		break;
	}
	printf("\n");
	bb = TRUE;
	if (bb)
		printf("bb = TURE 입니다.\n");
	else
		printf("bb = FALSE 입니다.\n");
	return 0;
}