#include <stdio.h>
#include <stdlib.h>

void Linef(int cnt, char ch, FILE* stream);

void main(void)
{
	char name[10], jdab[26], idab[26], hak;
	int j, jcnt, jumsu;
	FILE *inf, *outf;
	if ( ( inf = fopen("..\\����.txt", "rt") ) == NULL)
	{
		printf("����.txt file open error \n");
		exit(0);
	}
	if ( ( outf = fopen("..\\���.txt", "wt") ) == NULL)
	{
		printf("���.txt file open error \n"), exit(0);
	}

	fprintf(outf, "%40s \n", "���� ���ǥ");
	Linef(72, '-', outf);
	fprintf(outf, " �� ��   ");
	for ( j = 0; j <= 25; j++)
	{
		fprintf(outf, "%2d", j);
	}
	fprintf(outf, "  ���� ���� \n");
	Linef(72, '-', outf);

	fscanf(inf, "%s", jdab);
	while ( fscanf(inf, "%10s%s", name, idab ) != EOF)
	{
		jcnt = 0;
		fprintf(outf, " %-8s", name);
		for ( j = 0; j < 25; j++)
		{
			if (idab[j] == jdab[j])
			{
				jcnt++;
				fprintf(outf, " O");
			}
			else
			{
				fprintf(outf, " X");
			}
		}
		jumsu = jcnt * 4;
		if (jumsu >= 90)
			hak = 'A';
		else if (jumsu >= 80)
			hak = 'B';
		else if (jumsu >= 70)
			hak = 'C';
		else if (jumsu >= 60)
			hak = 'D';
		else
			hak = 'F';
		fprintf(outf, "  %3d   %c \n", jumsu, hak);
	}
	Linef(72, '-', outf);
	fclose(inf);
	fclose(outf);
}

void Linef(int cnt, char ch, FILE* stream)
{
	int i;
	for (i = 0; i < cnt; i++)
	{
		putc(ch, stream);
	}
	putc('\n', stream);
}
