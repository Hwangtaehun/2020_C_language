#include <iostream>
using namespace std;

class CString
{
private:
	char* pBuffer;
public:
	CString();
	CString(char* pStr);
	~CString();
	void strcpy(char* sa, char* sb);
	int strlen(char* pStr);
	int GetLength();
	void operator += (char* pStr);
	void operator = (char* pStr);
	CString& operator = (const CString& str);
	char* GetStr()
	{
		return pBuffer;
	}
};

CString::CString()
{
	pBuffer = NULL;
}

CString::CString(char* pStr)
{
	int cnt;
	cnt = strlen(pStr);
	pBuffer = new char[cnt + 1];
	strcpy(pBuffer, pStr);
}

CString::~CString()
{

}

void CString::strcpy(char* sa, char* sb)
{
	while (*sb != NULL)
	{
		*sa = *sb;
		sa++;
		sb++;
	}
	*sa = NULL;
}

int CString::strlen(char* pStr)
{
	int n = 0;
	while (*pStr != NULL)
	{
		n++;
		pStr++;
	}
	return n;
}

int CString::GetLength()
{
	int n = 0;
	char* pStr;
	if (pBuffer == NULL)
		return 0;
	pStr = pBuffer;
	while (*pStr != NULL)
	{
		n++;
		pStr++;
	}
	return n;
}

void CString::operator += (char* pStr)
{
	int cnt1 = 0, cnt2 = 0;
	char* pTemp;
	if (pBuffer != NULL)
	{
		cnt1 = strlen(pBuffer);
		cnt2 = strlen(pStr);
		pTemp = pBuffer;
		pBuffer = new char[cnt1 + cnt2 + 1];
		strcpy(pBuffer, pTemp);
		delete[]pTemp;
	}
	strcpy(pBuffer + cnt1, pStr);
}

void CString::operator = (char* pStr)
{
	int cnt;
	if (pBuffer != NULL)
	{
		delete[]pBuffer;
		pBuffer = NULL;
	}
	cnt = strlen(pStr);
	pBuffer = new char[cnt + 1];
	strcpy(pBuffer, pStr);
}

CString& CString::operator = (const CString& str)
{
	int cnt;
	if (this != &str)
	{
		if (pBuffer != NULL)
		{
			delete[]pBuffer;
			pBuffer = NULL;
		}
		cnt = strlen(str.pBuffer);
		pBuffer = new char[cnt + 1];
		strcpy(pBuffer, str.pBuffer);
	}
	return *this;
}

int main(int argc, char** argv)
{
	CString sa((char*)"se"), sb((char*)"jong");
	cout << "sa.GetLength() = " << sa.GetLength() << " sb = " << sb.GetLength() << endl;
	cout << "sa = " << sa.GetStr() << " sb = " << sb.GetStr() << endl;

	sa = "sejong";
	cout << "sa =\"sejong\" 실행 수 sa = " << sa.GetStr() << " sb = " << sb.GetStr() << endl;

	sb = sa;
	cout << "sb = sa 실행 후 sa = " << sa.GetStr() << " sb = " << sb.GetStr() << endl;

	sb += "aaa";
	cout << "sb +=\"aaa\"실행 후 sa = " << sa.GetStr() << " sb = " << sb.GetStr() << endl;
	cout << "sa.GetLength() = " << sa.GetLength() << " sb = " << sb.GetLength() << endl;

	return 0;
}