#include <iostream>
using namespace std;

class CTest
{
protected:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest();
    ~CTest();
    void SetValue(int x, int y);
    void Plus_A();
    void Plus_B();
    void Plus_C();
    int GetResult();
};

 CTest::CTest() : m_nA(0), m_nB(0), m_nC(0)
 {

 }

CTest::~CTest()
{

}

void CTest::SetValue(int x, int y)
{
    m_nA = x;
    m_nB = y;
}

void CTest::Plus_A()
{
    cout << "���� Class�� Plus_A() ����\n";
    m_nC = m_nA + m_nB;
}

void CTest::Plus_B()
{
    cout << "���� Class�� Plus_B() ����\n";
    m_nC = m_nA + m_nB;
}

void CTest::Plus_C()
{
    cout << "���� Class�� Plus_C() ����\n";
    m_nC = m_nA + m_nB;
}

int CTest::GetResult()
{
    return m_nC;
}

class CTest_B : public CTest
{
public:
    CTest_B();
    ~CTest_B();
    void Plus_A();
    void Plus_B();
    void Plus_C();
};

CTest_B::CTest_B()
{

}

CTest_B::~CTest_B()
{

}

void CTest_B::Plus_A()
{
    cout << "�ڼ� Class�� Plus_A() ����\n";
    m_nC += 1000;
}

void CTest_B::Plus_B()
{
    CTest::Plus_B();
    cout << "�ڼ� Class�� Plus_B() ����\n";
    m_nC += 1000;
}

void CTest_B::Plus_C()
{
    cout << "�ڼ� Class�� Plus_C() ����\n";
    m_nC += 1000;
    CTest::Plus_C();
}

int main()
{
    CTest_B sj;
    sj.SetValue(11, 22);
    sj.Plus_A();
    cout << "sj.Plus_A() ���� �� m_nC = " << sj.GetResult() << endl;
    sj.Plus_B();
    cout << "sj.Plus_B() ���� �� m_nC = " << sj.GetResult() << endl;
    sj.Plus_C();
    cout << "sj.Plus_C() ���� �� m_nC = " << sj.GetResult() << endl;
    return 0;
}
