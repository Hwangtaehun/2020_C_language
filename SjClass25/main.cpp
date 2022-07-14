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
     cout << "CTest 생성자함수 실행 \n";
 }

CTest::~CTest()
{
    cout << "CTest 소멸자함수 실행 \n";
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
     cout << "CTest_B 생성자함수 실행 \n";
}

CTest_B::~CTest_B()
{
    cout << "CTest_B 소멸자함수 실행 \n";
}

void CTest_B::Minus()
{
    //m_nD = 100;
    m_nC = m_nA - m_nB;
}

int main()
{
    CTest_B sj;
    cout << "main  시작 \n";
    sj.SetValue(11, 22);
    sj.Plus();
    cout << "sj.Plus() 실행 후 m_nC = " << sj.GetResult() << endl;
    cout << " main 끝\n";
    return 0;
}
