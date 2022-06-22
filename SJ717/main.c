#include <stdio.h>
#include <stdlib.h>

int m_abs(int n);
double m_fabs(double X);

int main()
{
    int a = -5, b;
    double x;

    b = m_abs(a); //abs(a);
    x = m_fabs(-5.5); //fabs(-5.5);

    printf("b = %d\n", b);
    printf("x = %.2f\n", x);
    return 0;
}

int m_abs(int n){
    int m;
    if( m < 0)
        m = -n;
    else
        m = n;
    return m;
}

double m_fabs(double X){
    double temp;
    temp = ( ( X < 0.0 ) ? -X : X );
    return temp;
}
