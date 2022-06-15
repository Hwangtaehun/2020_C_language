#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a=100, b, c;

    if( 65 <= a <= 90 )
        printf("0 이 아닌 수는 참\n");
    else
        printf("0 이 아닌 수는 거짓\n");

    if( 0 )
        printf("0 은 참\n");
    else
        printf("0 은 거짓\n");

    a = 5 > 6;
    b = 5 < 6;

    c = (5<6) + (5<6);
    printf("a = %d, b = %d, c = %d \n", a, b, c);

    return 0;
}
