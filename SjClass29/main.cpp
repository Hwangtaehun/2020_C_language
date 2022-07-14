#include <iostream>
using namespace std;

class CTest
{
public:
    CTest();
    virtual ~CTest();
    void Plus();
    virtual void Minus();
};

CTest::CTest()
{

}

CTest::~CTest()
{
    cout << "������ �Ҹ��� ����" << endl;
}

void CTest::Plus()
{
    cout << "������ Plus() ����" << endl;
}

void CTest::Minus()
{
    cout << "������ Minus() ����" << endl;
}

class CTest_B : public CTest
{
public:
    CTest_B();
    ~CTest_B();
    void Plus();
    virtual void Minus();
};

CTest_B::CTest_B()
{

}

CTest_B::~CTest_B()
{
    cout << "�ڼ��� �Ҹ��� ����" << endl;
}

void CTest_B::Plus()
{
    cout << "�ڼ��� Plus() ����" << endl;
}

void CTest_B::Minus()
{
    cout << "�ڼ��� Minus() ����" << endl;
}

int main()
{
    CTest *pt;
    CTest_B sj;
    pt = new CTest_B;
    cout << "pt->Plus()    : ";
    pt->Plus();
    cout << "pt->Minus() : ";
    pt->Minus();
    cout << "sj.Plus()       : ";
    sj.Plus();
    cout << "sj.Minus()     : ";
    sj.Minus();
    delete pt;
    return 0;
}
