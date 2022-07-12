#include <iostream>
using namespace std;
class CTest
{
protected:
    int m_nA;
    int m_nB;
public:
    CTest(int x);
    ~CTest();
    void Print();
};

CTest::CTest(int x)
{
    m_nA = x;
    cout << "생성자 실행 m_nA = " << m_nA << endl;
}

CTest::~CTest()
{
    cout << "소멸자 실행 m_nA = " << m_nA << endl;
}

void Sub(int x);

int main()
{
    cout << " main 시작 \n";
    Sub(11);
    Sub(22);
    Sub(33);
    cout << " main 끝 \n";
    return 0;
}

void Sub(int x)
{
    static CTest ss (99);
    CTest aa(x);
    cout << "sub의 x = " << x << endl;
}
