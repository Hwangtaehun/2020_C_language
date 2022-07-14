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
    void operator++();
    void print(const char *str);
};

CTest::CTest() : m_nA(10), m_nB(10)
{

}

CTest::~CTest()
{

}

void CTest::Increase()
{
    m_nA += 1;
    m_nB += 1;
}

void CTest::operator++()
{
    m_nA += 1;
    m_nB += 1;
}

void CTest::print(const char *str)
{
    cout << str << m_nA << ", " << m_nB << endl;
}

int main()
{
    CTest sja, kbs;
    sja.print("sja.Increase() 실행 전 = ");
    sja.Increase();
    sja.print("sja.Increase() 실행 후 = ");
    sja.operator++();
    sja.print(" sja.operator++() 실행 후 = ");
    ++sja;
    sja.print("++sja 실행 후 = ");
    kbs = sja;
    kbs.print("kbs = sja 실행 후 kbs = ");
    int num = 123;
    cout << num;
    cout.operator<<(num);
    return 0;
}
