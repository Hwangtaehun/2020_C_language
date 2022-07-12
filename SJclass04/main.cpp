#include <iostream>
#include "sungjuk.h"
using namespace std;

int main()
{
    CSungJuk kbs;

    kbs.SetName("¿Õ°Ç");
    kbs.SetScore(90, 80, 70);
    kbs.CompScore();
    cout << kbs.GetName() << "ÀÇ ÃÑÁ¡Àº " << kbs.GetTot() << "Á¡\n";
    return 0;
}
