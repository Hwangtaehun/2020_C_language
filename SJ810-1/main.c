#include <stdio.h>

void Line(int cnt, char ch);

int main()
{
    char name[5][10];
    int kor[5], eng[5], mat[5], tot[5];
    int i;
    printf(" 5명의 이름 국어 영어 수학을 입력하세요. \n");
    for(i = 0; i < 5; i++)
    {
        scanf(" %s %d %d %d", name[i], &kor[i], &eng[i], &mat[i]);
        tot[i] = kor[i] + eng[i] + mat[i];
    }

    printf("%22s\n", "성적현황");
    Line(35, '=');
    printf("이 름     국어 영어 수학 총점 \n");
    Line(35, '=');
    for(i = 0; i < 5; i++)
    {
        printf("%-8s %3d %3d %3d %3d %6.2f\n", name, kor, eng, mat, tot);
    }
    Line(35, '=');

    return 0;
}

void Line(int cnt, char ch)
{
    int i;
    for(i = 0; i < cnt; i++)
    {
        putchar(ch);
    }
    putchar('\n');
}
