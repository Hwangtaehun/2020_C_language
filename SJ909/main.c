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
    FILE *inf, *outf;
    struct SUNG data;
    if((inf = fopen("..\\sungjuk.txt", "rt")) == NULL)
        printf("sungjuk.txt file open error \n"), exit(0);
    if((outf = fopen("record.dat", "wb")) == NULL)
        printf("record.dat file open error \n"), exit(0);

    while(fscanf(inf, "%8s%3d%3d%3d", data.name, &data.kor, &data.eng, &data.mat) != EOF)
    {
        fwrite(&data, sizeof(struct SUNG), 1, outf);
    }
    fclose(inf);
    fclose(outf);
    return 0;
}
