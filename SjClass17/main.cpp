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

void Sub1();
void Sub2();

int main()
{
	CTest sj;
	cout << "main ���۽� sj.cnt     = " << sj.cnt << endl;
	cout << "main ���۽� CTest::cnt = " << CTest::cnt << endl;
	Sub1();
	cout << "Sub1 ������ sj.cnt = " << sj.cnt << endl;
	CTest* pt1 = new CTest;
	CTest* pt2 = new CTest;
	cout << "new ������ sj.cnt = " << sj.cnt << endl;
	cout << "new ������ pt1->cnt = " << pt1->cnt << endl;
	delete pt1;
	cout << "delete������ sj.cnt = " << sj.cnt << endl;
	delete pt2;
	cout << "main ������ sj.cnt = " << sj.cnt << endl;
	return 0;
}

void Sub1()
{
	CTest aa;
	cout << "Sub1 ���۽� aa.cnt = " << aa.cnt << endl;
	Sub2();
	cout << "Sub1 ���۽� aa.cnt = " << aa.cnt << endl;
}

void Sub2()
{
	CTest bb;
	cout << "Sub2 ������ bb.cnt = " << bb.cnt << endl;

}
