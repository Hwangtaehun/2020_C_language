#include <iostream>
using namespace std;

class CTest
{
private:
    int m_nA;
    int m_nB;
public:
    CTest();
    ~CTest();
    void Increase();
    CTest &operator++();
    CTest operator++(int n);
    void Print(const char *str);
};

CTest::CTest() : m_nA(10), m_nB(10)
{

}

CTest::~CTest()
{

}

CTest &CTest::operator++()
{
    m_nA += 1;
    m_nB += 1;
    return *this;
}

CTest CTest::operator++(int n)
{
    CTest temp = *this;
    m_nA += 1;
    m_nB += 1;
    return temp;
}

void CTest::Print(const char *str)
{
    cout << str << m_nA << ", " << m_nB << endl;
}


int main()
{
    CTest sja, kbs, sjb, mbc;
    kbs = ++sja;
    sja.Print("kbs = ++sja 실행 후 sja = ");
    kbs.Print("kbs = ++sja 실행 후 kbs = ");
    kbs = ++++sja;
    sja.Print("kbs = ++++sja 실행 후 sja = ");
    kbs.Print("kbs = ++++sja 실행 후 kbs = ");

    mbc = sjb++;
    sjb.Print("mbc = sjb++ 실행 후 sjb = ");
    mbc.Print("mbc = sjb++ 실행 후 mbc = ");

    mbc = sjb++++;
    sjb.Print("mbc = sjb++++ 실행 후 sjb = ");
    mbc.Print("mbc = sjb++++ 실행 후 mbc = ");
    return 0;
}
