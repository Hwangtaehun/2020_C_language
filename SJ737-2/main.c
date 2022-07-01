#include <stdio.h>

int Factorial(int n);
int Fibonacci(int cnt);
int Gcm2(int a, int b);

int main(void){
    int n, m, gcm;
    printf("n factorial \n");
    for(n = 1; n < 9; n++)
    {
        printf( "%d! = %5d \n", n, Factorial(n) );
    }
    printf("n 번째 Fibonacci 수 \n");
    for(n = 1; n < 9; n++)
    {
        printf("%d! = %5d \n", n, Fibonacci(n));
    }
    n = 32;
    m = 12;
    gcm = Gcm2( n, m);
    printf("%d, %d의 최대공약수 = %d\n", n, m, gcm);
    return 0;
}

int Factorial(int n)
{
    if(n<=1)
        return 1;
    else
        return n * Factorial(n-1);
}

int Fibonacci(int cnt)
{
    if(cnt <= 2)
    {
        return 1;
    }
    else
    {
        return (Fibonacci(cnt - 1)+ Fibonacci(cnt - 2));
    }
}

int Gcm2(int a, int b)
{
    if(b == 0)
        return a;
    else
        return Gcm2(b, a%b);
}
