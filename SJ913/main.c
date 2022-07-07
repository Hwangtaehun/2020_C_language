#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

struct SUNG
{
	char name[10];
	int kor;
	int eng;
	int mat;
	int tot;
};

int main(void)
{
	int hd;
	struct SUNG data;
	hd = open("..\\sample.dat", O_RDONLY | O_BINARY);
	if (hd == -1)
		printf("sample.dat open error\n"), exit(0);
	printf("이  름   국어  영어  수학  총점\n");

	lseek(hd, 0L, SEEK_SET);

	while (!eof(hd))
	{
		read(hd, (void*)&data, sizeof(struct SUNG));
		printf("%-10s %5d %5d %5d %5d\n", data.name, data.kor, data.eng, data.mat, data.tot);
	}
	close(hd);
	return 0;
}
