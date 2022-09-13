// MyServerSocket.cpp: 구현 파일
//

#include "stdafx.h"
//#include "SjEchoServer.h"
#include "MyServerSocket.h"


// CMyServerSocket

CMyServerSocket::CMyServerSocket()
{
}

CMyServerSocket::~CMyServerSocket()
{
}


// CMyServerSocket 멤버 함수


void CMyServerSocket::OnAccept(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	//AfxMessageBox(_T("누군가 접속"));
	AfxGetMainWnd()->SendMessage(UM_ACCEPT);
	//m_pWnd->SendMessage(UM_ACCEPT);
	CSocket::OnAccept(nErrorCode);
}


void CMyServerSocket::SetMainWindow(CWnd* pWnd)
{
	// TODO: 여기에 구현 코드 추가.
	m_pWnd = pWnd;
}


bool CMyServerSocket::ServerStart(int nPort)
{
	// TODO: 여기에 구현 코드 추가.
	if (!Create(nPort))
	{
		return false;
	}
	if (!Listen())
	{
		return false;
	}
	return true;
}
