// SjServerSocket.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "SjEchoServerMulti2.h"
#include "SjServerSocket.h"


// CSjServerSocket

CSjServerSocket::CSjServerSocket()
{
}

CSjServerSocket::~CSjServerSocket()
{
}


// CSjServerSocket ��� �Լ�


void CSjServerSocket::OnAccept(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	m_pWnd->SendMessage(UM_ACCEPT);
	CSocket::OnAccept(nErrorCode);
}


bool CSjServerSocket::ServerStart(CWnd * pWnd, int nPortNo)
{
	m_pWnd = pWnd;
	if (!Create(nPortNo))
		return false;
	if (!Listen())
		return false;
	return true;
}
