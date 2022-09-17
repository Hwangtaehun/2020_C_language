#pragma once
#define UM_RECEIVE (WM_USER + 1)
#define UM_SOCKET_CLOSE (WM_USER + 3)
// CSjClientSocket 명령 대상입니다.

class CSjClientSocket : public CSocket
{
private:
	CWnd* m_pWnd;
public:
	CSjClientSocket();
	virtual ~CSjClientSocket();
	bool m_bFlag;						//사용 중인 상태를 나타내는 변수
	bool m_bConnect;					//연결 상태 나타내는 변수
	void SetMainWindow(CWnd* pWnd);
	virtual void OnReceive(int nErrorCode);
	virtual void OnClose(int nErrorCode);
	CString m_strName;
};
