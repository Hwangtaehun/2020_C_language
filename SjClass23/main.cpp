#include <iostream>
using namespace std;

class CTest
{
private:
    int m_nA;
    int m_nB;
public:
    CTest();
    ~CTest();
    void Increase();
    CTest operator+(CTest x);
    void Print(const char *str);
};

CTest::CTest() : m_nA(10), m_nB(10)
{

}

CTest::~CTest()
{

}

CTest CTest::operator+(CTest obj)
{
    CTest Temp;
    Temp.m_nA = m_nA + obj.m_nA;
    Temp.m_nB = m_nB + obj.m_nB;
    return Temp;
}

void CTest::Print(const char *str)
{
    cout << str << m_nA << ", " << m_nB << endl;
}

int main()
{
    CTest sja, sjb, kbs;
    kbs = sja + sjb;
    sja.Print("kbs = sja + sjb 실행 후 sja = ");
    sjb.Print("kbs = sja + sjb 실행 후 sjb = ");
    kbs.Print("kbs = sja + sjb 실행 후 kbs = ");
    return 0;
}
