#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

class CSungJuk
{
private:
	char m_strName[10];
	int m_nKor;
	int m_nEng;
	int m_nMat;
	int m_nTot;
public:
	CSungJuk();
	CSungJuk(char* name, int kor, int eng, int mat);
	~CSungJuk();
	void CompScore();
	void Print();
};

CSungJuk::CSungJuk()
{
	strcpy(m_strName, "default");
	m_nKor = m_nEng = m_nMat = 0;
}

CSungJuk::CSungJuk(char* name, int kor, int eng, int mat)
{
	strcpy(m_strName, name);
	m_nKor = kor;
	m_nEng = eng;
	m_nMat = mat;
}

CSungJuk::~CSungJuk()
{
	cout << "�Ҹ��� ����" << m_nTot << endl;
}

void CSungJuk::CompScore()
{
	m_nTot = m_nKor + m_nEng + m_nMat;
}

void CSungJuk::Print()
{
	cout << setw(12) << m_strName << "�� ������" << setw(3) << m_nTot << "�� " << this << endl;
}

int main(void)
{
	CSungJuk kbs("kbs", 90, 90, 90);
	CSungJuk mbc = CSungJuk("mbc", 80, 80, 80);

	CSungJuk kk[5] = { CSungJuk("�հ�", 90, 80, 70), CSungJuk("����", 60, 50, 40), CSungJuk("�ÿ�", 50, 90, 80) };

	cout << "CSungJuk�� ũ�� = " << sizeof(CSungJuk) << endl;

	kbs.CompScore();
	kbs.Print();
	mbc.CompScore();
	mbc.Print();

	int i;
	for (i = 0; i < sizeof(kk) / sizeof(CSungJuk); i++)
	{
		kk[i].CompScore();
		kk[i].Print();
	}

	return 0;
}
