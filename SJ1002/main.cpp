#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char **argv)
{
    int i =65;
    float f = 456.789f;

    cout << oct << "  8진수 = " << i << '\n';
    cout << hex << " 16진수 = " << i << '\n';
    cout << " i = " << i << '\n';
    dec(cout);

    cout.width(20);
    cout << "[10진수 = " << i << "]" << endl;
    cout.fill('=');
    cout << setw(20) << "[10진수 = " << i << "]" << endl;
    cout << left << setw(20) << "[10진수 = " << i << "]" << endl;
    cout << right << setfill('@') << setw(5) << "dd" << endl;

    cout << "f = " << f << endl;
    cout.precision(4);
    cout << "f = " << f << endl;

    cout << fixed;
    cout << "f = " << f << endl;
    cout << scientific;
    cout << setprecision(5) << "f = " << f << endl;

    return 0;
}
