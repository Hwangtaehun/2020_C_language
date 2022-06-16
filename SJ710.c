//SJ710
#include <stdio.h>

void sub();

int main() 
{
	printf("aaa\n");
	sub();
	printf("bbb\n");
	sub();
	printf("ccc\n");
	return 0;
}

void sub() 
{
	printf("sub 함수 호출됨\n");
	printf("sub 함수 실행중\n");
	printf("sub 함수 종료됨\n");

}