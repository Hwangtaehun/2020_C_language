#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100, b = 200;
    int *pt, **pp, ***rr;
    printf("a�� ������ %u, %p, %X �Դϴ�. \n", &a, &a, &a);
    printf("b�� ������ %u �Դϴ�. \n", &b);
    printf("pt�� ������ %u �Դϴ�. \n", &pt);
    printf("pp�� ������ %u �Դϴ�. \n", &pp);

    pt = &a;
    pp = &pt;
    printf("   pp = %u \n", pp);
    printf("  *pp = %d \n", *pp);
    printf(" **pp = %d \n", **pp);
    pt = &b;
    **pp = **pp + 5;
    printf("   pp = %u \n", pp);
    printf("  *pp = %d \n", *pp);
    printf(" **pp = %d \n", **pp);
    printf("    b = %d\n", b);

    rr = &pp;
    printf("   rr = %u \n", rr);
    printf("  *rr = %u \n", *rr);
    printf(" **rr = %u \n", **rr);
    printf("***rr = %u \n", ***rr);
    return 0;
}
