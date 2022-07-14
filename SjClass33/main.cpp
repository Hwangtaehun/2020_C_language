#include <iostream>
using namespace std;
template <typename T1, typename T2>
class CTest
{
private:
    T1 m_nA;
    T2 m_nB;
public:
    CTest(T1 x, T2 y);
    ~CTest();
    void SetValue(T1 x, T2 y);
    void Print();
};

template<typename T1, typename T2>
CTest<T1, T2>::CTest(T1 x, T2 y) : m_nA(x), m_nB(y)
{

}

template<typename T1, typename T2>
CTest<T1, T2>::~CTest()
{

}

template<typename T1, typename T2>
void CTest<T1, T2>::SetValue(T1 x, T2 y)
{
    m_nA = x;
    m_nB = y;
}

template<typename T1, typename T2>
void CTest<T1, T2>::Print()
{
    cout << "m_nA = " << m_nA;
    cout << ", m_nB = " << m_nB << endl;
}

int main()
{
    CTest<int, double> sja(11, 22.22);
    sja.Print();
    CTest<double, int> sjb(33.33, 44);
    sjb.SetValue(55.5, 22.2);
    sjb.Print();
    return 0;
}
