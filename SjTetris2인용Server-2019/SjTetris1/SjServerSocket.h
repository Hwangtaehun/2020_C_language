#pragma once
#define UM_ACCEPT (WM_USER + 2)
// CSjServerSocket 명령 대상입니다.

class CSjServerSocket : public CSocket
{
private:
	CWnd* m_pWnd;
public:
	CSjServerSocket();
	virtual ~CSjServerSocket();
	virtual void OnAccept(int nErrorCode);
	bool ServerStart(CWnd* pWnd, int nPortNo);
};




