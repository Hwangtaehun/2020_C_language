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
    cout << "CTest 인수없는 생성자함수 실행 \n";
    m_nA = 11;
}

CTest::CTest(int x, int y)
{
    cout << "CTest 인수있는 생성자함수 실행 \n";
    m_nA = x;
    m_nB = y;
}

CTest::~CTest()
{
    cout << m_nA << " CTest 소멸자함수 실행 \n";
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
     cout << "CTest_B 인수 없는 생성자함수 실행 \n";
     m_nB = 22;
}

CTest_B::CTest_B(int xx, int yy) : CTest(xx, yy)
{
     cout << "CTest_B 인수 있는 생성자함수 실행 \n";
}

CTest_B::~CTest_B()
{
    cout << m_nA <<" CTest 소멸자함수 실행 \n";
}

int main()
{
    CTest_B sj;
    sj.Print();
    CTest_B kbs(33, 44);
    kbs.Print();
    return 0;
}
