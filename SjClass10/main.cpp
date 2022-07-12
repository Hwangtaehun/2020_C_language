#include <iostream>

using namespace std;

class CTest
{
private:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest( int x = 10, int y = 20);
    ~CTest();

    void SetValue(int, int = 111);
    void Plus();
    int GetResult();
    void Print();
};

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
    CTest kbs(11, 22), mbc(33), cjb;
    cout << "kbs : ";
    kbs.Print();
    cout << "mbc : ";
    mbc.Print();
    cout << "cjb : ";
    cjb.Print();

    //kbs.SetValue();
    //kbs.SetValue(, 123);
    kbs.SetValue(333);

    cout << "SetValue(333) Ã³¸®ÈÄ kbs : ";
    kbs.Print();

    return 0;
}
