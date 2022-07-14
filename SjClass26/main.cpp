#include <iostream>
using namespace std;

class CTest
{
protected:
    int m_nA;
    int m_nB;
public:
    CTest();
    CTest(int x, int y);
    ~CTest();
    void Print();
};

CTest::CTest()
{
    cout << "CTest �μ����� �������Լ� ���� \n";
    m_nA = 11;
}

CTest::CTest(int x, int y)
{
    cout << "CTest �μ��ִ� �������Լ� ���� \n";
    m_nA = x;
    m_nB = y;
}

CTest::~CTest()
{
    cout << m_nA << " CTest �Ҹ����Լ� ���� \n";
}

void CTest::Print()
{
    cout << "m_nA = " << m_nA << endl;
    cout << "m_nB = " << m_nB << endl;
}

class CTest_B : public CTest
{
public:
    CTest_B();
    CTest_B(int x, int y);
    ~CTest_B();
};

CTest_B::CTest_B()
{
     cout << "CTest_B �μ� ���� �������Լ� ���� \n";
     m_nB = 22;
}

CTest_B::CTest_B(int xx, int yy) : CTest(xx, yy)
{
     cout << "CTest_B �μ� �ִ� �������Լ� ���� \n";
}

CTest_B::~CTest_B()
{
    cout << m_nA <<" CTest �Ҹ����Լ� ���� \n";
}

int main()
{
    CTest_B sj;
    sj.Print();
    CTest_B kbs(33, 44);
    kbs.Print();
    return 0;
}
