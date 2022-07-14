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
    cout << "선조의 소멸자 실행" << endl;
}

void CTest::Plus()
{
    cout << "선조의 Plus() 실행" << endl;
}

void CTest::Minus()
{
    cout << "선조의 Minus() 실행" << endl;
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
    cout << "자손의 소멸자 실행" << endl;
}

void CTest_B::Plus()
{
    cout << "자손의 Plus() 실행" << endl;
}

void CTest_B::Minus()
{
    cout << "자손의 Minus() 실행" << endl;
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
