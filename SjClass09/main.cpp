#include <iostream>
using namespace std;
class CTest
{
private:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest( int x, int y);
    ~CTest();
    void SetValue(int, int);
    void Plus();
    int GetResult();
    void Print();
};

CTest::CTest(int x, int y)
{
    m_nA = x;
    m_nB = y;
    cout << "생성자 실행 m_nA = " << m_nA << endl;
}

CTest::~CTest()
{
    cout << "소멸자 실행 m_nA = " << m_nA << endl;
}

void CTest::Plus()
{
    m_nC = m_nA + m_nB;
}

void CTest::SetValue(int x, int y)
{
    m_nA = x;
    m_nB = y;
}

int CTest::GetResult()
{
   return m_nC;
}

void CTest::Print()
{
    cout << "m_nA = " << m_nA << ", m_nB = " << m_nB << endl;
}

int main()
{
    CTest kbs(11, 22), mbc(33, 44);
    cout << "kbs : ";
    kbs.Print();
    cout << "mbc : ";
    mbc.Print();
    kbs.SetValue(44, 55);
    cout << "SetValue(44, 55) 처리 후 \nkbs : ";
    kbs.Print();
    kbs.Plus();
    cout << "Plus() 실행 후 결과 =" << kbs.GetResult() << endl;
    return 0;
}
