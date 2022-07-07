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

#define DATA_SIZE ( sizeof(struct SUNG) )

void ListRec(int hd);
void InsertRec(int hd);
void ModifyRec(int hd);
void SortFile(int hd);
void DiskSwap(int hd, int a, int b);

int main(void)
{
	int hd;
	char select = ' ';
	hd = open("..\\sample.dat", O_RDWR | _O_BINARY);
	if (hd == -1)
		printf("smaple.dat open error\n"), exit(0);

	while (select != '0')
	{
		printf("\n			   자 료  관 리\n");
		printf("===============================================\n");
		printf(" 1.추가  2.정정  3.정렬  4.현황  0.종료\n");
		printf("===============================================\n");
		printf("원하는 직업 번호를 입력 : ");
        fflush(stdin);
		select = getchar();
		fflush(stdin);
		printf("\n");

		switch (select)
		{
		case '1':
			InsertRec(hd);
			break;
		case '2':
			ModifyRec(hd);
			break;
		case '3':
			SortFile(hd);
			break;
		case '4':
			ListRec(hd);
			break;
		case '0':
			printf("\nProgramd을 종료합니다.\n");
			break;
		default:
			printf("\n작업 번호를 정확히 입력하세요. !!!\n");
		}
	}
	close(hd);
	return 0;
}

void ListRec(int hd)
{
	struct SUNG data;
	lseek(hd, 0L, SEEK_SET);
	printf("\n      현재 자료 현황 \n");
	printf("===============================================\n");
	printf("이    름    국어   영어   수학   총점\n");
	printf("===============================================\n");

	while (!eof(hd))
	{
		read(hd, (void*)&data, DATA_SIZE);
		printf("%-10s %5d %5d %5d \n", data.name, data.kor, data.eng, data.mat, data.tot);
	}
	printf("===============================================\n");
}

void InsertRec(int hd)
{
	struct SUNG data;
	lseek(hd, 0L, SEEK_END);
	printf("\n자료 추가 \n");
	printf("이   름 : ");
	scanf("%s", data.name);
	printf("국   어 : ");
	scanf("%s", &data.kor);
	printf("영   어 : ");
	scanf("%s", &data.eng);
	printf("수   학 : ");
	scanf("%s", &data.mat);
	data.tot = data.kor + data.eng + data.mat;

	write( hd, (void *)&data, DATA_SIZE);
	printf("추가 되었습니다.!!!\n");
}

void ModifyRec(int hd)
{
	struct SUNG data;
	long last;
	int cnt, n;
	last = lseek(hd, 0L, SEEK_END);
	cnt = (int)(last / (long)DATA_SIZE);

	printf("\n정정할 Record 번호 : ");
	scanf("%d", &n);
	if (n >= cnt)
	{
		printf("정정할 Record가 없습니다!!!\n");
		return;
	}
	lseek(hd, (long)DATA_SIZE*n, SEEK_SET);
	read(hd, (void*)&data, DATA_SIZE);
	printf("%d 번째의 내용 : %-10s %5d %5d %5d \n", n, data.name, data.kor, data.eng, data.mat);

	printf("\n정정할 내용을 입력 하세요. \n");
	printf("이   름 : ");
	scanf("%s", data.name);
	printf("국   어 : ");
	scanf("%s", &data.kor);
	printf("영   어 : ");
	scanf("%s", &data.eng);
	printf("수   학 : ");
	scanf("%s", &data.mat);
	data.tot = data.kor + data.eng + data.mat;

	lseek(hd, (long)DATA_SIZE*n, SEEK_SET);
	write(hd, (void *)&data, DATA_SIZE);
	printf("정정 되었습니다.!!!\n");
}

void SortFile(int hd)
{
	struct SUNG data1, data2;
	long last;
	int a, b, c, cnt, tot;
	char select;

	last = lseek(hd, 0L, SEEK_END);
	cnt = (int)(last / (long)DATA_SIZE);

	printf("1.오름차순 2.내림차순 선택 : ");
	select = getchar();
	fflush(stdin);

	for (a = 0; a < cnt - 1; a++)
	{
		lseek(hd, (long)DATA_SIZE *a, SEEK_SET);
		read(hd, (void*)&data1, DATA_SIZE);
		tot = data1.tot;
		c = a;

		for ( b = a + 1; b < cnt; b++)
		{
			lseek(hd, (long)DATA_SIZE *b, SEEK_SET);
			read(hd, (void*)&data2, DATA_SIZE);
			if (select == '1')
			{
				if (tot > data2.tot)
					c = b, tot = data2.tot;
			}
			else
			{
				if (tot < data2.tot) c = b, tot = data2.tot;
			}
		}
		if (c != a)
			DiskSwap(hd, a, c);
	}

	if (select == '1')
		printf("오름차순으로 정렬되었습니다.\n");
	else
		printf("내림차순으로 정렬되었습니다.\n");
}

void DiskSwap(int hd, int a, int b)
{
	struct SUNG data1, data2;
	lseek(hd, (long)DATA_SIZE *a, SEEK_SET);
	read(hd, (void*)&data1, DATA_SIZE);
	lseek(hd, (long)DATA_SIZE *a, SEEK_SET);
	read(hd, (void*)&data2, DATA_SIZE);

	lseek(hd, (long)DATA_SIZE *b, SEEK_SET);
	write(hd, (void*)&data1, DATA_SIZE);
	lseek(hd, (long)DATA_SIZE *a, SEEK_SET);
	write(hd, (void*)&data2, DATA_SIZE);
}
