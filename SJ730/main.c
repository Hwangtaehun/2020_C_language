#include <stdio.h>
#include <stdlib.h>

void ArrayPrn1(int *pt);
void ArrayPrn2(int pt[]);

int main()
{
    int k[5] = {1,2,3,4,5};

    ArrayPrn1(k);

    ArrayPrn2(k);

    return 0;
}

void ArrayPrn1(int *pt)
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%5d", pt[i]);
    }
    printf("\n");
}

void ArrayPrn2(int pt[])
{
    int i;
    for(i = 0; i < 5; i++)
    {
        printf("%5d", *pt++);
    }
    printf("\n");
}
