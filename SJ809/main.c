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

void Sub_A(SUNG pp);
SUNG Sub_B(SUNG pp);
void Sub_C(SUNG *pt);

int main(int argc, char **argv)
{
    SUNG sa, sb, sc = { "sejong", 99, 88, 77};
    sa = sb = sc;
    Sub_A(sa);
    sb = Sub_B(sb);
    Sub_C(&sc);
    printf("Sub_A È£Ãâ ÈÄ sa ÀÇ ÃÑÁ¡ = %d Æò±Õ = %.2f\n", sa.tot, sa.av);
    printf("Sub_B È£Ãâ ÈÄ sb ÀÇ ÃÑÁ¡ = %d Æò±Õ = %.2f\n", sb.tot, sb.av);
    printf("Sub_C È£Ãâ ÈÄ sc ÀÇ ÃÑÁ¡ = %d Æò±Õ = %.2f\n", sc.tot, sc.av);
    return 0;
}

void Sub_A(SUNG pp)
{
    pp.tot = pp.kor + pp.eng + pp.mat;
    pp.av = (float)pp.tot /3.0f;
    printf("Sub_A ¿¡¼­ ÃÑÁ¡ = %d Æò±Õ = %.2f\n", pp.tot, pp.av);
}

SUNG Sub_B(SUNG pp)
{
    pp.tot = pp.kor + pp.eng + pp.mat;
    pp.av = (float)pp.tot /3.0f;
    return pp;
}

void Sub_C(SUNG *pt)
{
    pt->tot =  pt->kor + pt->eng + pt->mat;
    pt->av = (float)pt -> tot / 3.0f;
}
