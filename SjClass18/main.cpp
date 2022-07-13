#include<iostream>
using namespace std;

class CTest
{
private:
	int m_nA;
	int m_nB;
public:
	static int cnt;
	CTest();
	~CTest();
	static void Prn();
};

int CTest::cnt = 0;

CTest::CTest()
{
	cnt++;
}

CTest::~CTest()
{
	cnt--;
}

void CTest::Prn()
{
	cout << " cnt = " << cnt << endl;
}

int main()
{
	CTest::Prn();
	CTest sj;
	sj.Prn();
	CTest::Prn();
	return 0;
}

