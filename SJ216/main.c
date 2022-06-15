#include <stdio.h>
#include <stdlib.h>

int main()
{
   int a=3, b=5, c, d;
   c = a & b;
   d = a | b;
   printf("%d & %d = %d \n", a, b, c);
   printf("%d | %d = %d \n", a, b, d);

   c = a ^ b;
   d = ~a;
   printf("%d ^ %d = %d \n", a, b, c);
   printf("~%d = %d \n", a, d);

   d = d + 1;
   printf("%d의 2의 보수는 %d \n", a, d);

   c = a << 2;
   d = b >> 2;
   printf("%d << 2= %d \n", a, c);
   printf("%d >> 2= %d \n", b, d);
    return 0;
}
