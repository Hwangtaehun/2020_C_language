#include <iostream>
#include <cstdlib>
using namespace std;

class CTest
{
private:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest( int x = 0, int y = 0 );
    ~CTest();
    void SetValue(int x, int y);
    void Plus();
    int GetResult();
};

CTest::CTest( int x, int y ) : m_nA(x), m_nB(y)
{
    cout << "持失切  m_nA = " << m_nA << endl;
}

CTest::~CTest()
{
    cout << "社瑚切  m_nA = " << m_nA << endl;
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

int main()
{
    CTest sj(11, 22);
    sj.Plus();
    cout << "sj.GetResult() = " << sj.GetResult() << endl;
    CTest &rep = sj;
    CTest *pt = &sj;

    pt->SetValue(33, 44);
    pt->Plus();
    cout << "pt->GetResult() = " << pt->GetResult() << endl;
    cout << "rep.GetResult() = " << rep.GetResult() << endl;

    pt = new CTest(55, 66);
    pt->Plus();
    cout << "(*pt).GetResult() = " << (*pt).GetResult() << endl;

    CTest *pt2;
    cout << "sizeof(CTest) = " << sizeof(CTest) << endl;
    pt2 = (CTest *)malloc(sizeof(CTest));
    pt2->Plus();
    cout << "pt2->GetResult() = " << pt2->GetResult() << endl;
    return 0;
}
