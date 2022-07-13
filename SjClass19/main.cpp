#include <iostream>
#include <cstring>
using namespace std;

class CSungJuk
{
public:
	char m_strName[10];
	int m_nKor;
	int m_nEng;
	int m_nMat;
	int m_nTot;
	void CompScore()
	{
		m_nTot = m_nKor + m_nEng + m_nMat;
	}
};

int main(void)
{
	CSungJuk kk[4] = { {"¿Õ°Ç", 90, 80, 70}, {"°ßÈØ", 60, 50, 40}, {"±Ã¿¹", 50, 90, 80}, {"½Å¼þ°â", 100, 100, 100} };
	int i;
	for (i = 0; i < sizeof(kk)/sizeof(CSungJuk); i++)
	{
		kk[i].CompScore();
		cout << kk[i].m_strName << "ÀÇ ÃÑÁ¡Àº " << kk[i].m_nTot << "Á¡\n";
	}

	return 0;
}
