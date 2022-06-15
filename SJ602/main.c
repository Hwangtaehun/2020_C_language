#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100, b = 200;
    int *pt, **pp, ***rr;
    printf("a의 번지는 %u, %p, %X 입니다. \n", &a, &a, &a);
    printf("b의 번지는 %u 입니다. \n", &b);
    printf("pt의 번지는 %u 입니다. \n", &pt);
    printf("pp의 번지는 %u 입니다. \n", &pp);

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
