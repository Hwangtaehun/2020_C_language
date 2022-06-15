#include <stdio.h>
#include <stdlib.h>

int main()
{
   int arr[5] = {10, 20, 30, 40, 50};
   int i, *ipt;
   double d = 100, *fpt;
   char c = 'A';
   for(i=0; i<5;i++)
    {
    printf("arr[%d]의 번지는 %u 입니다. \n", i, &arr[i]);
   }
   printf("배열대표명 arr = %u, &arr[0] = %u\n", arr, &arr[0]);
   printf("*arr = %d\n", *arr);
   ipt = &i;
   fpt = &d;
   printf("&c = %u, (&c+1) = %u\n", &c, (&c+1));
   printf("&i = %u, (&i+1) = %u\n", &i, (&i+1));
   printf("ipt = %u, ipt+1 = %u\n", ipt, ipt+1);
   printf("fpt = %u, fpt+1 = %u\n", fpt, fpt+1);
    return 0;
}
