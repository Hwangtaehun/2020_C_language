#include <iostream>
#include <cstring>
using namespace std;

template <typename T>
T Plus(T a, T b)
{
    return a+b;
}

template<>char * Plus(char *a, char *b)
{
    char *pp = new char[strlen(a) + strlen(b) + 1];
    strcpy(pp, a);
    strcat(pp, b);
    return pp;
}

template <typename T1, typename T2> void Print(T1 t1, T2 t2)
{
    cout << "t1 = " << t1;
    cout << ", t2 = " << t2 << endl;
}

template<typename T>
void Swap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

int main()
{
    int a = 3, b = 5;
    double c = 3.3, d =5.5;
    char *p1 = "se", *p2 = "jong";

    cout << "Plus<int>(3,5) : " << Plus<int>(3,5) <<endl;
    cout << "Plus<double>(3.3,5.5) : " << Plus<double>(3.3,5.5) <<endl;
    cout << "Plus(p1, p2) : " << Plus(p1, p2) << endl;

    cout << "Print<int, double>(11.1, 22.2) : ";
    Print<int, double>(11.1, 22.2);
    cout << "Print(11.1 , 22) : ";
    Print(11.1 , 22);

    Swap<int>(a, b);
    Swap<double>(c, d);
    cout << a << ',' << b << endl;
    cout << c << ',' << d << endl;
    return 0;
}
