#include <stdio.h>
typedef struct tag_Sung
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
    float av;
} SUNG;

void Avl(int cnt, SUNG s[]);
void NP(int cnt, SUNG s[]);
void PP(int cnt, SUNG *pSung);

int main( int argc, char **argv)
{
    SUNG s[] = { {"�հ�", 100, 100, 100},
                    {"����", 60, 50, 80},
                    {"�ÿ�", 50, 90, 80},
                    {"�ڼ�ȸ", 50, 60, 40},
                    {"�ż���", 70, 60, 90}
                   };

    int cnt;
    cnt = sizeof(s) / sizeof(SUNG);

    Avl(cnt, s);
    NP(cnt, s);
    PP(cnt, s);

    return 0;
}


void Avl(int cnt, SUNG s[])
{
    int i;
   // printf("%d\n", sizeof(s) / sizeof(SUNG));

    for(i = 0; i < cnt ; i++)
    {
        s[i].tot = s[i].kor + s[i].eng + s[i].mat;
        s[i].av = (float)s[i].tot / 3.0f;
    }
}

void NP(int cnt, SUNG s[])
{
    int i;
    printf("����ü �迭�� ����(÷�� ���) \n");
    for(i = 0; i < cnt ; i++)
    {
        printf("%-7s %3d %3d %3d %3d %6.2f\n", s[i].name, s[i].kor, s[i].eng, s[i].mat, s[i].tot, s[i].av);
    }
}

void PP(int cnt, SUNG *pSung)
{
    int i;
    printf("����ü �迭�� ����(pointer ���) \n");
    for(i = 0; i < cnt ; i++)
    {
        printf("%-7s %3d %3d %3d %3d %6.2f\n", pSung->name, pSung->kor, pSung->eng, pSung->mat, pSung->tot, pSung->av);
        pSung ++;
    }
}
