#include <stdio.h>
#include <stdlib.h>

int fibonacci(int n);

int main() {
    int n;

    for(n=1; n<10; n++){
        printf(" %d ¹øÂ° = %5d \n", n, fibonacci(n));
    }

	return 0;
}

int fibonacci(int n){
    int num1 = 1, num2 = 0, num3, cnt = 0;

	do
	{
		num3 = num1 + num2;
		num1 = num2;
		num2 = num3;
		cnt++;
	} while (cnt < n);
	return num3;
}
