#include <stdio.h>
#include <stdlib.h>
#include <io.h>
#include <fcntl.h>
#include <sys/stat.h>

int main()
{
    int hd;
    hd = creat("..\\sample.dat", S_IREAD | S_IWRITE);

    if(hd == -1)
        printf("sample.dat open error\n"), exit(0);
    printf("hd = %d \n", hd);
    close(hd);
    return 0;
}
