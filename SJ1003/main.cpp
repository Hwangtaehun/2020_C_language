#include <iostream>
#include <fstream>
using namespace std;

int main(int argc, char **argv)
{
    ofstream outf;
    ifstream inf;
    char ch = 'A';
    int i = 1234;
    double f = 456.789;
    cout << " File 에 기록 후 다시 출력\n";
    outf.open("test.txt", ios::out);
    outf << ch << ' ' << i << ' ' << f;
    outf.close();

    outf.open("test.txt", ios::app);
    outf << 'B' << ' ' << 5678 << ' ' << 123.56;
    outf.close();

    inf.open("test.txt");
    inf >> ch >> i >> f;
    cout << " ch = " << ch << '\n';
    cout << " i = " << i << '\n';
    cout << " f = " << f << endl;
    inf >> ch >> i >> f;
    cout << " ch = " << ch << '\n';
    cout << " i = " << i << '\n';
    cout << " f = " << f << endl;
    inf.close();
    return 0;
}
