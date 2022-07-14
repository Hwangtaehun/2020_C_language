#include <iostream>
using namespace std;
template <typename T1>
class CTest
{
private:
    T1 m_nA;
public:
    CTest(T1 x);
    ~CTest();
    void Print(T1 t1);
};

template<typename T1>
CTest<T1>::CTest(T1 x) : m_nA(x)
{

}

template<typename T1>
CTest<T1>::~CTest()
{

}

template<typename T1> void CTest<T1>::Print(T1 t1)
{
    cout << "m_nA = " << m_nA;
    cout << ", t1 = " << t1 << endl;
}

int main()
{
    CTest<int>sja(11);
    sja.Print(22);

    CTest<double>sjb(11.11);
    sjb.Print(22.22);
    return 0;
}
