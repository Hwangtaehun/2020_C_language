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
    char ch;
    struct SUNG data;

    hd = open ("..\\sample.dat", O_WRONLY|O_BINARY);

    if(hd == -1)
        printf("sample.dat open error\n"), exit(0);

    do{
        printf("\n\n 자 료 입 력 \n");

        printf("이   름 : ");
        scanf("%s", data.name);
        printf("국   어 : ");
        scanf("%s", &data.kor);
        printf("영   어 : ");
        scanf("%s", &data.eng);
        printf("수   학 : ");
        scanf("%s", &data.mat);
        data.tot = data.kor + data.eng + data.mat;

        lseek(hd, 0L, SEEK_END);
        lseek(hd, sizeof(struct SUNG)*2L, SEEK_SET);

        write(hd, (void *)&data, sizeof(struct SUNG) );
        printf("\n 계속 하시겠습니까 ? (Y/N) : ");
        ch=getch();
    }while(ch == 'y' || ch == 'Y' );
    close(hd);
    return 0;
}
