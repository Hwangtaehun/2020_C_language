#include <stdio.h>
#include <stdlib.h>

/*int main()
{
    printf("[%d] [%2d] [%6d]\n", 123, 123, 123);

    printf("[%06d] [%-6d] [%+6d]\n", 123, 123, 123);

    printf("[%0*d] [%0*d]\n", 6, 123, 5, 123);

    printf("[%o] [%x] [%X]\n", 123, 255, 255);

    printf("[%f] [%4.2f] [%10.2f]\n", 123.456, 123.456, 123.456);
    printf("[%.2f] [%10.3e] [%10.2E]\n", 123.456, 123.456, 123.456);

    printf("[%g][%4.2g][%10.4g]\n", 123.456, 123.456, 123.456);

    printf("[%c] [%6c] [-%6c]\n", 'A', 'B', 'C');

    printf("[%s] [%10s] [%-10s]\n", "abcde", "fghijk", "jklm");
    printf("[%3s] [%10.3s]\n", "abcde", "fghijk");
    return 0;
}*/

/*sj105.c: ������ �ڷ� 2�� �Է� �� ���*/
/*int main(){

int aa, bb;
printf("���� 2�� �Է� \n");
scanf("%d%d", &aa, &bb);
printf("aa = %d, bb = %d \n", aa, bb);

return 0;
}*/

/*<1-1>
int main(){

    int a, b;
    printf("���� 2�� �Է� \n");
    scanf("%d%d", &a, &b);
    printf("�� = %d \n", a+b);
    printf("�� = %d \n", a-b);

    return 0;
}
*/

/*<1-2>
int main(){

    int a, b, c;
    printf("���� ���� : ");
    scanf("%d", &a);
    printf("���� ���� : ");
    scanf("%d", &b);
    printf("���� ���� : ");
    scanf("%d", &c);
    printf("\n������ %d ��, ����� %d ���Դϴ�.\n", a+b+c, (a+b+c)/3);

    return 0;
}
*/

int main(){

    int a, b, c;
    printf("���� : ");
    scanf("%4d%2d%2d", &a, &b, &c);
    printf("\n������ %d�� %d�� %d���̰� ���̴� %d���Դϴ�.\n", a, b, c, 2010-a);

    return 0;
}
