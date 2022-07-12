#include <iostream>
#include <cstring>
using namespace std;

struct SungJuk
{
    char name[10];
    int kor;
    int eng;
    int mat;
    int tot;
    void CompScore()
    {
        tot = kor + eng + mat;
    }
};

void CompScore(SungJuk *pt);

int main()
{
    SungJuk kbs;
    strcpy(kbs.name, "세종");
    kbs.kor = 90;
    kbs.eng = 80;
    kbs.mat = 70;

   // kbs.tot = kbs.kor + kbs.eng +kbs.mat;
   //CompScore(&kbs);
   kbs.CompScore();

    cout << kbs.name << "의 총점은 " << kbs.tot << "점\n";
    return 0;
}

//void CompScore(SungJuk *pt)
//{
//    pt->tot = pt->kor + pt->eng + pt->mat;
//}
