#include <iostream>
using namespace std;

class CTest
{
private:
    int m_nD;
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
     cout << "CTest �������Լ� ���� \n";
 }

CTest::~CTest()
{
    cout << "CTest �Ҹ����Լ� ���� \n";
}

void CTest::SetValue(int x, int y)
{
    m_nA = x;
    m_nB = y;
}

void CTest::Plus()
{
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
};

CTest_B::CTest_B()
{
     cout << "CTest_B �������Լ� ���� \n";
}

CTest_B::~CTest_B()
{
    cout << "CTest_B �Ҹ����Լ� ���� \n";
}

void CTest_B::Minus()
{
    //m_nD = 100;
    m_nC = m_nA - m_nB;
}

int main()
{
    CTest_B sj;
    cout << "main  ���� \n";
    sj.SetValue(11, 22);
    sj.Plus();
    cout << "sj.Plus() ���� �� m_nC = " << sj.GetResult() << endl;
    cout << " main ��\n";
    return 0;
}
