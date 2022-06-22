#include <stdio.h>

void Sub(void);

int main(){
    printf("main함수 시작 \n");
    sub();
    printf("main함수 끝\n");

    return 0;
}

void sub(void){
    printf("Sub함수 시작 \n");
    printf("Sub함수 실행\n");

    return;

    rpintf("Sub함수 끝\n");
}
