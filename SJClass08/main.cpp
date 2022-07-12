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
    cout << "CTest 생성자함수 실행\n";
    m_nA = 100;
    m_nB = 200;
}

CTest::~CTest()
{
    cout << "CTest 소멸자함수 실행 \n";
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
    cout << " main 시작 \n";
    //sj.SetValue(11, 22);
    sj.Plus();
    cout << sj.GetResult() << endl;
    sub();
    cout << " main 끝\n";
    return 0;
}

void sub()
{
    CTest aa, bb;
    cout << " Sub 실행 \n";
}
