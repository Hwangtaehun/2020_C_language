#include <iostream>
#include "sungjuk.h"
using namespace std;

int main()
{
    CSungJuk kbs;

    kbs.SetName("�հ�");
    kbs.SetScore(90, 80, 70);
    kbs.CompScore();
    cout << kbs.GetName() << "�� ������ " << kbs.GetTot() << "��\n";
    return 0;
}
