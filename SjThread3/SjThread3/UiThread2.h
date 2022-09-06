#pragma once



// CUiThread2

class CUiThread2 : public CWinThread
{
	DECLARE_DYNCREATE(CUiThread2)

protected:
	CUiThread2();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CUiThread2();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


