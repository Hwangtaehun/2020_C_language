#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	char* pt[5], buf[100];
	int i, j, cnt;

	for (i = 0; i < 5; i++)
	{
		scanf("%s", buf);

		cnt = 0;
		while (buf[cnt] != NULL)
			cnt++;

		pt[i] = new char[cnt + 1];
		for (j = 0; j <= cnt; j++) {
			*(pt[i] + j) = *(buf + j);
		}
	}

	for (i = 0; i < 5; i++)
		printf("%s\n", pt[i]);

	return 0;
}