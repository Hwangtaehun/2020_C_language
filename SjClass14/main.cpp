#include <iostream>
#include <cstring>
using namespace std;

class CTest
{
private:
    int m_nA;
    char *m_pName;
public:
    CTest(int x, const char *pName);
    CTest(const CTest &parm);
    ~CTest();
    void SetValue(int x, char *pName);
    void Print();
};

CTest::CTest(int x, const char *pName)
{
    m_nA = x;
    m_pName = new char[strlen(pName)+1];
    strcpy(m_pName, pName);
}
CTest::CTest(const CTest &parm)
{
    m_nA = parm.m_nA;
    m_pName = new char[strlen(parm.m_pName)+1];
    strcpy(m_pName, parm.m_pName);
}
CTest::~CTest()
{
    delete []m_pName;
}
void CTest::SetValue(int x, char *pName)
{
    m_nA = x;
    strcpy(m_pName, pName);
}
void CTest:: Print()
{
    cout << m_nA << ", " << m_pName << endl;
}

void printObject(CTest kk);
CTest returnObject();

int main()
{
    CTest kbs(11, "kbs");
    CTest mbc(kbs);
    cout << "kbs1 : ";
    kbs.Print();
    cout << "mbc1 : ";
    mbc.Print();
    mbc.SetValue(22, "mbc");
    cout << "kbs2 : ";
    kbs.Print();
    cout << "mbc2 : ";
    mbc.Print();
    cout << "prn2 : ";
    printObject(mbc);
    kbs = returnObject();
    cout << "kbs3 : ";
    kbs.Print();
    return 0;
}

void printObject(CTest kk)
{
    kk.Print();
}

CTest returnObject()
{
    CTest sj(33, "sejong");
    cout << "func : ";
    sj.Print();
    return sj;
}
