#include <stdio.h>
#include <stdlib.h>

int Hap(int cnt);

int main()
{
    int a;
    a = Hap(10);
    printf("a = %d\n", a);
    printf("Hap(100) = %d\n", Hap(100));

    return EXIT_SUCCESS;
}

int Hap(int cnt){
    int i, tot = 0;
    for(i = 1; i <= cnt; i++)
    {
        tot += i;
    }
    return tot;
}
