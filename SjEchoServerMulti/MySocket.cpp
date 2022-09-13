// MySocket.cpp : ���� �����Դϴ�.
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


// CMySocket ��� �Լ�


void CMySocket::OnReceive(int nErrorCode)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	//AfxMessageBox(_T("Socket�� �޽����� ����"));
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
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	AfxMessageBox(_T("Close �޽����� ����"));
	m_bConnect = false;
	Close();
	CSocket::OnClose(nErrorCode);
}
