// SjClientSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjEchoServerMulti2.h"
#include "SjClientSocket.h"


// CSjClientSocket

CSjClientSocket::CSjClientSocket()
: m_pWnd(NULL)
, m_bFlag(false)
, m_bConnect(false)
{
}

CSjClientSocket::~CSjClientSocket()
{
}


// CSjClientSocket ��� �Լ�


void CSjClientSocket::SetMainWindow(CWnd * pWnd)
{
	m_pWnd = pWnd;
}


void CSjClientSocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pWnd->SendMessage(UM_RECEIVE, 0, (LPARAM)this);   //LPARAM�� �ڽ��� ������ ��� ����
	CSocket::OnReceive(nErrorCode);
}


void CSjClientSocket::OnClose(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pWnd->SendMessage(UM_SOCKET_CLOSE, 0, (LPARAM)this);  //LPARAM�� �ڽ��� ������ ��� ����
	CSocket::OnClose(nErrorCode);
}
