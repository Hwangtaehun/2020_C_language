#include <iostream>

using namespace std;

class CTest
{
private:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest( void );
    CTest( int x );
    CTest( int x, int y );
    ~CTest();

    void SetValue(int, int);
    void SetValue(int);
    void Plus();
    int GetResult();
    void Print();
};

CTest::CTest(void)
{
    m_nA = 100;
    m_nB = 200;
}

CTest::CTest(int x)
{
    m_nA = m_nB = x;
}

CTest::CTest(int x, int y)
{
    m_nA = x;
    m_nB = y;
}

CTest::~CTest()
{
}

void CTest::SetValue(int x, int y)
{
    m_nA = x;
    m_nB = y;
}

void CTest::SetValue(int y)
{
    m_nA = m_nB = y;
}

void CTest::Plus()
{
    m_nC = m_nA + m_nB;
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
    CTest kbs(11), mbc(33, 44), sj;
    cout << "sj : ";
    sj.Print();
    cout << "kbs : ";
    kbs.Print();
    cout << "mbc : ";
    mbc.Print();
    kbs.SetValue(333);
    cout << "SetValue(333) 贸府饶 kbs : ";
    kbs.Print();
    kbs.SetValue(77, 88);
    cout << "kbs.SetValue(77, 88) 贸府饶 kbs : ";
    kbs.Print();

    return 0;
}
