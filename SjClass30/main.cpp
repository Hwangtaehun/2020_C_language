#include <iostream>
using namespace std;

class CTest
{
private:
    int m_nA;
protected:
    int m_nB;
public:
    int m_nC;
    CTest();
    virtual ~CTest();
};

 CTest::CTest() : m_nA(10), m_nB(10), m_nC(10)
 {

 }

CTest::~CTest()
{

}

class CTest_B : public CTest
{
public:
    int m_nD;
    CTest_B();
    virtual ~CTest_B();
    void Print();
};

CTest_B::CTest_B() : m_nD(20)
{

}

CTest_B::~CTest_B()
{

}

void CTest_B::Print()
{
    cout << "CTest_B의 Print 함수에서 \n";
    cout << "m_nB = " << m_nB << endl;
    cout << "m_nC = " << m_nC << endl;
}

class CTest_C : private CTest
{
public:
    int m_nD;
    CTest_C();
    virtual ~CTest_C();
    void Print();
};

CTest_C::CTest_C() : m_nD(30)
{

}

CTest_C::~CTest_C()
{

}

void CTest_C::Print()
{
    cout << "CTest_C의 Print 함수에서 \n";
    cout << "m_nB = " << m_nB << endl;
    cout << "m_nC = " << m_nC << endl;
}

int main()
{
    CTest_B sj;
    sj.Print();
    cout << "sj.m_nC = " << sj.m_nC << endl;
    cout << "sj.m_nD = " << sj.m_nD << endl;

    CTest_C kbs;
    kbs.Print();
    cout << "kbs.m_nD = " << kbs.m_nD << endl;
    return 0;
}
