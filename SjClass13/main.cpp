#include <iostream>
using namespace std;

class CTest
{
private:
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
    cout << "CTest 인수 없는 기본 생성자 실행 \n";
    m_nA = 10;
    m_nB = 20;
}

CTest::CTest(int x, int y)
{
    cout << "CTest 인수 있는 기본 생성자 실행 \n";
    m_nA = x;
    m_nB = y;
}

CTest::~CTest()
{
    cout << "CTest 소멸자 실행 \n";
}

void CTest::Print()
{
    cout << "m_nA = " << m_nA << ", m_nB = " << m_nB << endl;
}

class CTest_A
{
private:
    int m_nC;
public:
    CTest m_Test;
    CTest_A();
    CTest_A(int x);
    ~CTest_A();
    void Print();
};

CTest_A::CTest_A()
{
    cout << "CTest_A 인수 없는 기본 생성자 실행 \n";
    m_nC = 111;
}

CTest_A::CTest_A(int x) : m_Test( x+1 , x)
{
    cout << "CTest_A 인수 있는 기본 생성자 실행 \n";
    m_nC = x;
}

CTest_A::~CTest_A()
{
    cout << "CTest_A 소멸자 실행 \n";
}

void CTest_A::Print()
{
    cout << "CTest_A m_nC = " << m_nC << endl;
}

int main()
{
    cout << "kbs \n";
    CTest_A kbs(3333);
    kbs.m_Test.Print();
    kbs.Print();

    cout << "mbc \n";
    CTest_A mbc;
    mbc.Print();

    return 0;
}
