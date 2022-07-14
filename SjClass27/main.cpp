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
    void Plus();
    int GetResult();
};

 CTest::CTest()
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

void CTest::Plus()
{
    cout << "���� Class�� Plus() ����\n";
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
    void Minus();
    void Plus();
};

CTest_B::CTest_B()
{

}

CTest_B::~CTest_B()
{

}

void CTest_B::Minus()
{
    m_nC = m_nA - m_nB;
}

void CTest_B::Plus()
{
    cout << "�ڼ� Class�� Plus() ����\n";
    m_nC = m_nA + m_nB + 10000;
}


int main()
{
    CTest_B sj;
    sj.SetValue(11, 22);
    sj.Plus();
    cout << "sj.Plus() ���� �� m_nC = " << sj.GetResult() << endl;
    sj.CTest::Plus();
    cout << "sj.CTest::Plus() ���� �� m_nC = " << sj.GetResult() << endl;
    sj.Minus();
    cout << "sj.Minus() ���� �� m_nC = " << sj.GetResult() << endl;
    return 0;
}
