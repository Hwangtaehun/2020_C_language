// SjClientSocket.cpp: 구현 파일
//

#include "pch.h"
#include "SjTetris1.h"
#include "SjClientSocket.h"


CSjClientSocket::CSjClientSocket()
	: m_pWnd(NULL)
	, m_bFlag(false)
	, m_bConnect(false)
{
	m_strName = _T("");
}

CSjClientSocket::~CSjClientSocket()
{
}


// CSjClientSocket 멤버 함수


void CSjClientSocket::SetMainWindow(CWnd* pWnd)
{
	m_pWnd = pWnd;
}


void CSjClientSocket::OnReceive(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pWnd->SendMessage(UM_RECEIVE, 0, (LPARAM)this);   //LPARAM에 자신의 번지를 담아 보냄
	CSocket::OnReceive(nErrorCode);
}


void CSjClientSocket::OnClose(int nErrorCode)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	m_pWnd->SendMessage(UM_SOCKET_CLOSE, 0, (LPARAM)this);  //LPARAM에 자신의 번지를 담아 보냄
	CSocket::OnClose(nErrorCode);
}


// CSjClientSocket 멤버 함수
