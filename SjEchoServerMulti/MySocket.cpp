// MySocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
//#include "SjEchoClient.h"
#include "MySocket.h"

LRESULT SendMessage(UINT message, WPARAM wParam = 0, LPARAM IParam = 0);
BOOL PostMessage(UINT message, WPARAM wParam = 0, LPARAM IParam = 0);

// CMySocket

CMySocket::CMySocket()
: m_pWnd(NULL)
, m_bReceive(false)
{
}

CMySocket::~CMySocket()
{
}


// CMySocket 멤버 함수


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//AfxMessageBox(_T("Socket에 메시지가 도착"));
	//AfxGetMainWnd()->SendMessage(WM_RBUTTONDBLCLK);
	//m_pWnd->SendMessage(WM_RBUTTONDBLCLK);

	//AfxGetMainWnd()->SendMessage(UM_RECEIVE);
	m_bReceive = true;
	//AfxGetMainWnd()->PostMessage(UM_RECEIVE);
	AfxGetMainWnd()->SendMessage(UM_RECEIVE, 0, (LPARAM)this);
	CSocket::OnReceive(nErrorCode);
}


void CMySocket::SetMainWindow(CWnd * pWnd)
{
	m_pWnd = pWnd;
}


void CMySocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	AfxMessageBox(_T("Close 메시지가 도착"));
	m_bConnect = false;
	Close();
	CSocket::OnClose(nErrorCode);
}
