#pragma once



// ssewer

class ssewer : public CWinThread
{
	DECLARE_DYNCREATE(ssewer)

protected:
	ssewer();           // 동적 만들기에 사용되는 protected 생성자입니다.
	virtual ~ssewer();

public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

protected:
	DECLARE_MESSAGE_MAP()
};


