#include "my.h"
typedef struct tag_Sung
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
} SUNG;

void Write(SUNG s[]);
void NP(SUNG s[]);

int main( int argc, char **argv)
{
    SUNG s[5];
    Write(s);
    NP(s);

    return 0;
}

void Write(SUNG s[])
{
    int i;
    printf(" 5���� �̸� ���� ���� ������ �Է��ϼ���. \n");
    for(i = 0; i < 5; i++)
    {
        scanf(" %s %d %d %d", s[i].name, &s[i].kor, &s[i].eng, &s[i].mat);
        s[i].tot = s[i].kor + s[i].eng + s[i].mat;
    }
}

void NP(SUNG s[])
{
    int i;
        printf("%22s\n", "������Ȳ");
    Line(35, '=');
    printf("�� ��     ���� ���� ���� ���� \n");
    Line(35, '=');
    for(i = 0; i < 5; i++)
    {
        printf("%-8s %5d %5d %5d %5d \n", s[i].name, s[i].kor, s[i].eng, s[i].mat, s[i].tot);
    }
    Line(35, '=');
}
