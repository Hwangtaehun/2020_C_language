#include <stdio.h>
#include <stdlib.h>

struct SUNG
{
	char name[10];
	int kor;
	int eng;
	int mat;
};

int main(int argc, char **argv)
{
    FILE *inf;
    struct SUNG data;
    int cnt;
    if((inf = fopen("..\\record.dat", "rb")) == NULL)
        printf("record.dat file open error \n"), exit(0);

    fseek(inf, 0L, SEEK_SET);

    while(1)
    {
        fread(&data, sizeof(struct SUNG), 1, inf);
        if(feof(inf))
            break;

        printf("%-10s%4d%4d%4d\n", data.name, data.kor, data.eng, data.mat);
    }
    fclose(inf);
    return 0;
}
