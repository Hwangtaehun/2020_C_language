#pragma once



// CUiThread1

class CUiThread1 : public CWinThread
{
	DECLARE_DYNCREATE(CUiThread1)

protected:
	CUiThread1();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~CUiThread1();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
public:
	int Run();
};


