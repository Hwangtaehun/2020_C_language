// MySocket.cpp : ���� �����Դϴ�.
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


// CMySocket ��� �Լ�


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//AfxMessageBox(_T("Socket�� �޽����� ����"));
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
