#include<iostream>
using namespace std;

class CTest
{
private:
	int m_nA;
	int m_nB;
	int m_nc;
public:
	CTest(int x, int y);
	~CTest();
	void Print();
};

CTest::CTest(int x, int y)
{
	m_nA = x;
	this->m_nB = m_nB;
}

CTest::~CTest()
{

}

int m_nA = 777;

void CTest::Print()
{
	int m_nA = 888;
	cout << " ObjectÀÇ ÁÖ¼Ò : " << this << endl;
	cout << " this->m_nA = " << this->m_nA;
	cout << " m_nA = " << m_nA;
	cout << " ::m_nA = " << ::m_nA;
	cout << " m_nB = " << m_nB << endl;
}

int main()
{
	CTest aa(11, 22), bb(33, 44), cc(55, 66);
	aa.Print();
	bb.Print();
	cc.Print();

	return 0;
}
