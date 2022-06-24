#include <stdio.h>

int my_abs(int x);
float my_abs(float x);
double my_abs(double x);

int main() 
{
	int ii;
	float ff;
	double dd;
	ii = my_abs(-5);
	printf("int 형 절대값 my_abs(-5) = %d\n", ii);
	ff = my_abs(-5.5f);
	printf("float 형 절대값 my_abs(-5.5f) = %6.2f\n", ff);
	dd = my_abs(-5.5);
	printf("double 형 절대값 my_abs(-5) = %6.2lf\n", dd);
	return 0;
}

int my_abs(int x)
{
	printf("my_abs(int x) 실행됨\n");
	return ((x < 0) ? -x : x);
}

float my_abs(float x)
{
	printf("my_abs(float x) 실행됨\n");
	return ((x < 0) ? -x : x);
}

double my_abs(double x)
{
	printf("my_abs(double x) 실행됨\n");
	return ((x < 0) ? -x : x);
}