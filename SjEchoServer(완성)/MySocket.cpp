// MySocket.cpp : 구현 파일입니다.
//

#include "stdafx.h"
//#include "SjEchoClient.h"
#include "MySocket.h"


// CMySocket

CMySocket::CMySocket()
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
	AfxGetMainWnd()->PostMessage(UM_RECEIVE);
	CSocket::OnReceive(nErrorCode);
}


void CMySocket::SetMainWindow(CWnd * pWnd)
{
	m_pWnd = pWnd;
}
