#include <iostream>

using namespace std;
class CTest
{
private:
    int m_nA;
    int m_nB;
    int m_nC;
public:
    CTest();
    ~CTest();
    void SetValue(int, int);
    void Plus();
    int GetResult();
};

CTest::CTest()
{
    cout << "CTest �������Լ� ����\n";
    m_nA = 100;
    m_nB = 200;
}

CTest::~CTest()
{
    cout << "CTest �Ҹ����Լ� ���� \n";
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

void sub();

int main()
{
    CTest sj;
    cout << " main ���� \n";
    //sj.SetValue(11, 22);
    sj.Plus();
    cout << sj.GetResult() << endl;
    sub();
    cout << " main ��\n";
    return 0;
}

void sub()
{
    CTest aa, bb;
    cout << " Sub ���� \n";
}
