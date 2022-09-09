
// SjEchoServerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjEchoServer.h"
#include "SjEchoServerDlg.h"
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


// CSjEchoServerDlg ��ȭ ����



CSjEchoServerDlg::CSjEchoServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjEchoServerDlg::IDD, pParent)
	, m_nPortNo(1234)
	, m_strMsg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSjEchoServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_BT, m_ctrlStartBt);
	DDX_Control(pDX, IDC_STOP_BT, m_ctrlStopBt);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDX_Control(pDX, IDC_MESSAGE, m_ctrlMsg);
	DDX_Text(pDX, IDC_MESSAGE, m_strMsg);
}

BEGIN_MESSAGE_MAP(CSjEchoServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BT, &CSjEchoServerDlg::OnClickedStartBt)
	ON_BN_CLICKED(IDC_STOP_BT, &CSjEchoServerDlg::OnClickedStopBt)
	ON_MESSAGE(UM_ACCEPT, &CSjEchoServerDlg::OnAcceptMsg)
	ON_MESSAGE(UM_RECEIVE, &CSjEchoServerDlg::OnReceiveMsg)
END_MESSAGE_MAP()


// CSjEchoServerDlg �޽��� ó����

BOOL CSjEchoServerDlg::OnInitDialog()
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
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSjEchoServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjEchoServerDlg::OnPaint()
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
HCURSOR CSjEchoServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjEchoServerDlg::OnClickedStartBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	/*m_Server.Create(1234);
	m_Server.Listen();*/
	UpdateData(TRUE);
	m_ctrlStartBt.EnableWindow(FALSE);
	m_ctrlStartBt.SetWindowText(_T("Server ������"));
	if (!m_Server.ServerStart(m_nPortNo))
	{
		MessageBox(_T("Server Socket ���� �߻�"));
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Sever Start"));
		return;
	}
	m_ctrlStopBt.EnableWindow(TRUE);
	m_strMsg += "Server ���� �� ��� ���Դϴ�.\r\n";
	UpdateData(FALSE);
}


void CSjEchoServerDlg::OnClickedStopBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfxMessageBox(_T("Server�� �����մϴ�!!"), MB_YESNO) == IDYES)
	{
		m_ctrlStopBt.EnableWindow(FALSE);
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Sever Start"));
		m_Server.ShutDown();
		m_Server.Close();
		m_Client.Close();
		m_strMsg += "Server�� �����մϴ�. \r\n";
		UpdateData(FALSE);
	}
	/*m_Server.Close();*/
}


LRESULT CSjEchoServerDlg::OnAcceptMsg(WPARAM wParam, LPARAM IParam)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	// MessageBox(_T("UM_ACCEPT �޼��� ����"));
	char Buf[100] = "�ȳ��ϼ��� ������ \r\n Echo Server�ε��� \r\n";
	if (!m_Server.Accept(m_Client))
	{
		MessageBox(_T("Client ���� ����"));
		return -1;
	}
	m_Client.SetMainWindow(this);
	if (m_Client.Send(Buf, 100) == -1)
	{
		MessageBox(_T("Message ���� ����"));
		return -1;
	}
	m_strMsg += "������ ���� �߽��ϴ�.\r\n";
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
	/*m_Server.Accept(m_Client);
	m_Client.SetMainWindow(this);
	m_Client.Send(Buf, 100);*/
}


LRESULT CSjEchoServerDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	// MessageBox(_T("UM_RECEIVE �޼��� ����"));
	char Buf1[100], Buf2[100];
	m_Client.Receive(Buf2, 100);
	sprintf_s(Buf1, "Server : %s\r\n", Buf2, 100);
	if (m_Client.Send(Buf1, 100) == -1)
	{
		MessageBox(_T("Message ���� ����"));
		return -1;
	}
	m_strMsg += "Client : ";
	m_strMsg += Buf2;
	m_strMsg += "\r\n";
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
	/*char Buf1[100], Buf2[100];
	m_Client.Receive(Buf2, 100);
	sprintf_s(Buf1, "Server : %s\r\n", Buf2, 100);
	m_Client.Send(Buf1, 100);*/
}
