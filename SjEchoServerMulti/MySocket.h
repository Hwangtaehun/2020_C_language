#pragma once
#define UM_RECEIVE (WM_USER + 1)
// CMySocket ��� ����Դϴ�.

class CMySocket : public CSocket
{
private:
	CWnd *m_pWnd;
public:
	CMySocket();
	virtual ~CMySocket();
	virtual void OnReceive(int nErrorCode);
	void SetMainWindow(CWnd * pWnd);
	bool m_bReceive;
	bool m_bConnect;
	virtual void OnClose(int nErrorCode);
};


