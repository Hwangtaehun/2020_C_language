#pragma once
#define UM_ACCEPT (WM_USER + 2)

// CMyServerSocket 명령 대상

class CMyServerSocket : public CSocket
{
private:
	CWnd* m_pWnd;
public:
	CMyServerSocket();
	virtual ~CMyServerSocket();
	virtual void OnAccept(int nErrorCode);
	void SetMainWindow(CWnd* pWnd);
	bool ServerStart(int nPort);
};


