#pragma once
#define UM_RECEIVE (WM_USER + 1)
#define UM_SOCKET_CLOSE (WM_USER + 3)
// CSjClientSocket 명령 대상입니다.

class CSjClientSocket : public CSocket
{
private:
	CWnd *m_pWnd;
public:
	CSjClientSocket();
	virtual ~CSjClientSocket();
	bool m_bFlag;
	bool m_bConnect;
	void SetMainWindow(CWnd * pWnd);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
};


