#include <stdio.h>

typedef struct tage_Sung
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
    float av;
} SUNG;

int main(int argc, char **argv)
{
    SUNG ss = { "sejong", 99, 88, 77};
    SUNG *pt;
    pt = &ss;

    (*pt).tot = (*pt).kor + (*pt).eng + (*pt).mat;
    (*pt).av = (float)(*pt).tot / 3.0f;
    printf("ÃÑÁ¡ = %5d Æò±Õ = %.2f\n", ss.tot, ss.av);

    pt->kor = 100;
    pt->eng = 100;
    pt->mat = 100;
    pt->tot =  pt->kor + pt->eng + pt->mat;
    pt->av = (float)pt -> tot / 3.0f;

    printf("ÃÑÁ¡ = %5d Æò±Õ = %.2f\n", ss.tot, ss.av);

    printf("(*pt).name = %s pt->name = %s\n", (*pt).name, pt->name);
    printf("*(*pt).name = %c *pt->name = %c\n", *(*pt).name, *pt->name);
    return 0;
}
