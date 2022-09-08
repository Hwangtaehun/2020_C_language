
// SjEchoClientDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjEchoClient.h"
#include "SjEchoClientDlg.h"
#include "afxdialogex.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ���� ���α׷� ������ ���Ǵ� CAboutDlg ��ȭ �����Դϴ�.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// ��ȭ ���� �������Դϴ�.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

// �����Դϴ�.
protected:
	DECLARE_MESSAGE_MAP()
public:
//	virtual BOOL PreTranslateMessage(MSG* pMsg);
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSjEchoClientDlg ��ȭ ����



CSjEchoClientDlg::CSjEchoClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjEchoClientDlg::IDD, pParent)
	, m_strIpAddress(_T("localhost"))
	, m_nPortNo(1234)
	, m_strSendData(_T(""))
	, m_strReceiveData(_T(""))
	, m_bConnect(false)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSjEchoClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONNECT_BT, m_ctrlConnectBt);
	DDX_Control(pDX, IDC_DISCONNECT_BT, m_ctrlDisConnectBt);
	DDX_Control(pDX, IDC_SEND_BT, m_ctrlSendBt);
	DDX_Text(pDX, IDC_IPADDRESS, m_strIpAddress);
	DDX_Control(pDX, IDC_IPADDRESS, m_ctrlIpAddress);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDX_Text(pDX, IDC_SEND_DATA, m_strSendData);
	DDX_Control(pDX, IDC_SEND_DATA, m_ctrlSendData);
	DDX_Text(pDX, IDC_RECEIVE_DATA, m_strReceiveData);
	DDX_Control(pDX, IDC_RECEIVE_DATA, m_ctrlReceiveData);
}

BEGIN_MESSAGE_MAP(CSjEchoClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_CONNECT_BT, &CSjEchoClientDlg::OnClickedConnectBt)
	ON_BN_CLICKED(IDC_DISCONNECT_BT, &CSjEchoClientDlg::OnClickedDisconnectBt)
	ON_BN_CLICKED(IDC_SEND_BT, &CSjEchoClientDlg::OnClickedSendBt)
	ON_WM_RBUTTONDBLCLK()
	ON_MESSAGE( UM_RECEIVE, &CSjEchoClientDlg::OnReceiveMsg )
END_MESSAGE_MAP()


// CSjEchoClientDlg �޽��� ó����

BOOL CSjEchoClientDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �ý��� �޴��� "����..." �޴� �׸��� �߰��մϴ�.

	// IDM_ABOUTBOX�� �ý��� ��� ������ �־�� �մϴ�.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSjEchoClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSjEchoClientDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CSjEchoClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjEchoClientDlg::OnClickedConnectBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_Socket.Create();
	m_Socket.SetMainWindow(this);
	if (!m_Socket.Connect(m_strIpAddress, m_nPortNo))
	{
		MessageBox(_T("Sever�� �������� ���߳��� !!"));
		m_Socket.Close();
		return;
	}
	m_ctrlConnectBt.EnableWindow(FALSE);
	m_ctrlConnectBt.SetWindowText(_T("Server������"));
	m_ctrlSendBt.EnableWindow(TRUE);
	m_ctrlDisConnectBt.EnableWindow(TRUE);
	m_ctrlSendData.SetFocus();
	m_bConnect = TRUE;

	//CSocket m_Socket;
	/*m_Socket.Create();
	m_Socket.Connect(_T("localhost"), 1234);
	m_Socket.m_pWnd = this;*/

	/*char buf[100];
	m_Socket.Receive(buf, 100);
	m_strReceiveData += buf;
	UpdateData(FALSE);*/
}


void CSjEchoClientDlg::OnClickedDisconnectBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfxMessageBox(_T("Sever���� ������ �������� !!"), MB_YESNO) == IDYES)
	{
		m_ctrlConnectBt.EnableWindow(TRUE);
		m_ctrlConnectBt.SetWindowText(_T("Server����"));
		m_ctrlSendBt.EnableWindow(FALSE);
		m_ctrlDisConnectBt.EnableWindow(FALSE);
		m_ctrlSendData.SetFocus();
		m_Socket.Close();
		m_bConnect = FALSE;
	}
	/*m_Socket.Close();*/
}


void CSjEchoClientDlg::OnClickedSendBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char buf[100] = "";
	int n;
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		strcpy_s(buf, 100, CT2A(m_strSendData));
		n = m_Socket.Send(buf, 100);
		if (n == -1)
			MessageBox(_T("���۽���"));
		m_strSendData = "";
		UpdateData(FALSE);
	}
	m_ctrlSendData.SetFocus();

	/*strcpy_s(buf, 100, CT2A(m_strSendData));
	m_Socket.Send(buf, 100);*/

	/*char buf2[100];
	m_Socket.Receive(buf2, 100);
	m_strReceiveData += buf2;
	UpdateData(FALSE);*/
}


void CSjEchoClientDlg::OnRButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	AfxMessageBox(_T("WM_RBUTTONDBLCLK �޽����� ����"));
	char buf[100];
	m_Socket.Receive(buf, 100);
	m_strReceiveData += buf;
	UpdateData(FALSE);
	CDialogEx::OnRButtonDblClk(nFlags, point);
}


LRESULT CSjEchoClientDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	//MessageBox(_T("UM_RECEIVE �޽��� ����"));
	char buf[100];
	m_Socket.Receive(buf, 100);
	m_strReceiveData += buf;
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);
	return LRESULT();
}


BOOL CSjEchoClientDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return true;
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_RETURN)
	{
		if (m_bConnect)
			OnClickedSendBt();
		else
			OnClickedConnectBt();
		return TRUE;
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}
