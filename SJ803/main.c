#include <stdio.h>
#include <string.h>

struct SungJuk
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
};

int main()
{
    struct SungJuk kbs;
    strcpy(kbs.name, "ø’∞«");
    kbs.kor = 100;
    kbs.eng = 100;
    kbs.mat = 100;
    kbs.tot =  kbs.kor + kbs.eng + kbs.mat;
    printf(" %s¿« √—¡°¿∫ %d ¡° ¿‘¥œ¥Ÿ. \n", kbs.name, kbs.tot);
    return 0;
}
