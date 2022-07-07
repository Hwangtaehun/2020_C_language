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
		printf("\n			   �� ��  �� ��\n");
		printf("===============================================\n");
		printf(" 1.�߰�  2.����  3.����  4.��Ȳ  0.����\n");
		printf("===============================================\n");
		printf("���ϴ� ���� ��ȣ�� �Է� : ");
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
			printf("\nProgramd�� �����մϴ�.\n");
			break;
		default:
			printf("\n�۾� ��ȣ�� ��Ȯ�� �Է��ϼ���. !!!\n");
		}
	}
	close(hd);
	return 0;
}

void ListRec(int hd)
{
	struct SUNG data;
	lseek(hd, 0L, SEEK_SET);
	printf("\n      ���� �ڷ� ��Ȳ \n");
	printf("===============================================\n");
	printf("��    ��    ����   ����   ����   ����\n");
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
	printf("\n�ڷ� �߰� \n");
	printf("��   �� : ");
	scanf("%s", data.name);
	printf("��   �� : ");
	scanf("%s", &data.kor);
	printf("��   �� : ");
	scanf("%s", &data.eng);
	printf("��   �� : ");
	scanf("%s", &data.mat);
	data.tot = data.kor + data.eng + data.mat;

	write( hd, (void *)&data, DATA_SIZE);
	printf("�߰� �Ǿ����ϴ�.!!!\n");
}

void ModifyRec(int hd)
{
	struct SUNG data;
	long last;
	int cnt, n;
	last = lseek(hd, 0L, SEEK_END);
	cnt = (int)(last / (long)DATA_SIZE);

	printf("\n������ Record ��ȣ : ");
	scanf("%d", &n);
	if (n >= cnt)
	{
		printf("������ Record�� �����ϴ�!!!\n");
		return;
	}
	lseek(hd, (long)DATA_SIZE*n, SEEK_SET);
	read(hd, (void*)&data, DATA_SIZE);
	printf("%d ��°�� ���� : %-10s %5d %5d %5d \n", n, data.name, data.kor, data.eng, data.mat);

	printf("\n������ ������ �Է� �ϼ���. \n");
	printf("��   �� : ");
	scanf("%s", data.name);
	printf("��   �� : ");
	scanf("%s", &data.kor);
	printf("��   �� : ");
	scanf("%s", &data.eng);
	printf("��   �� : ");
	scanf("%s", &data.mat);
	data.tot = data.kor + data.eng + data.mat;

	lseek(hd, (long)DATA_SIZE*n, SEEK_SET);
	write(hd, (void *)&data, DATA_SIZE);
	printf("���� �Ǿ����ϴ�.!!!\n");
}

void SortFile(int hd)
{
	struct SUNG data1, data2;
	long last;
	int a, b, c, cnt, tot;
	char select;

	last = lseek(hd, 0L, SEEK_END);
	cnt = (int)(last / (long)DATA_SIZE);

	printf("1.�������� 2.�������� ���� : ");
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
		printf("������������ ���ĵǾ����ϴ�.\n");
	else
		printf("������������ ���ĵǾ����ϴ�.\n");
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
