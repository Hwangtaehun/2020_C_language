#include <stdio.h>

int main() {
	char sta[5] = { 'A', 'B', 'C', 'D', '\0' };
	char stb[5] = { 'A', 'B', 'C', 'D' };
	char stc[5] = "ABCD";
	int i;

	printf("sta = %s\n", sta);
	printf("stb = %s\n", stb);
	printf("stc = %s\n", stc);

	printf("한 문자씩 따로따로 출력합니다.\n");
	for ( i = 0; i < 5; i++)
	{
		putchar(sta[i]);
	}
	putchar('\n');

	printf("배열중 일부만 바꾼 후 출력합니다.\n");
	sta[1] = 'X';
	sta[3] = 'Y';
	printf("sta = %s \n", sta);

	return 0;
}
