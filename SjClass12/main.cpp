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
    cout << "������ ���� m_nA = " << m_nA << endl;
}

CTest::~CTest()
{
    cout << "�Ҹ��� ���� m_nA = " << m_nA << endl;
}

void Sub(int x);

int main()
{
    cout << " main ���� \n";
    Sub(11);
    Sub(22);
    Sub(33);
    cout << " main �� \n";
    return 0;
}

void Sub(int x)
{
    static CTest ss (99);
    CTest aa(x);
    cout << "sub�� x = " << x << endl;
}
