#include <stdio.h>

typedef struct tag_SUNG
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
} SUNG;


/*struct SungJuk
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
};
typedef struct SungJuk SUNG;*/

int main()
{
    SUNG kbs = {"�հ�", 99, 99, 99};
    kbs.tot = kbs.kor + kbs.eng + kbs.mat;
    printf(" %s�� ������ %d �� �Դϴ�. \n", kbs.name, kbs.tot);
    return 0;
}
