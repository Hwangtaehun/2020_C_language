
// SjEchoServerMultiDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjEchoServerMulti.h"
#include "SjEchoServerMultiDlg.h"
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


// CSjEchoServerMultiDlg ��ȭ ����



CSjEchoServerMultiDlg::CSjEchoServerMultiDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjEchoServerMultiDlg::IDD, pParent)
	, m_nPortNo(1234)
	, m_strMsg(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nCnt = 0;
}

void CSjEchoServerMultiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_BT, m_ctrlStartBt);
	DDX_Control(pDX, IDC_STOP_BT, m_ctrlStopBt);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDV_MinMaxInt(pDX, m_nPortNo, 0, 65535);
	DDX_Text(pDX, IDC_MESSAGE, m_strMsg);
	DDX_Control(pDX, IDC_MESSAGE, m_ctrlMsg);
}

BEGIN_MESSAGE_MAP(CSjEchoServerMultiDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_MESSAGE(UM_ACCEPT, &CSjEchoServerMultiDlg::OnAcceptMsg)
	ON_MESSAGE(UM_RECEIVE, &CSjEchoServerMultiDlg::OnReceiveMsg)
	ON_BN_CLICKED(IDC_START_BT, &CSjEchoServerMultiDlg::OnClickedStartBt)
	ON_BN_CLICKED(IDC_STOP_BT, &CSjEchoServerMultiDlg::OnClickedStopBt)
END_MESSAGE_MAP()


// CSjEchoServerMultiDlg �޽��� ó����

BOOL CSjEchoServerMultiDlg::OnInitDialog()
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

void CSjEchoServerMultiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjEchoServerMultiDlg::OnPaint()
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
HCURSOR CSjEchoServerMultiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CSjEchoServerMultiDlg::OnAcceptMsg(WPARAM wParam, LPARAM IParam)
{
	char strMsg1[DATA_SIZE] = "�ȳ��ϼ��� ������ \r\n Echo Server�ε��� \r\n";
	char strMsg2[DATA_SIZE] = "���� �ο� �ʰ��Դϴ�.\r\n��� �� �ٽ� �̿��� �ּ���! \r\n";
	char Buf[DATA_SIZE];
	int n;
	for (n = 0; n < MAX_USER - 1; n++)
	{
		if (!m_Client[n].m_bConnect)
			break;
	}
	if (!m_Server.Accept(m_Client[n]))
	{
		MessageBox(_T("Client ���� ����"));
		return -1;
	}
	if (n < MAX_USER - 1)
	{
		m_Client[n].SetMainWindow(this);
		m_Client[n].m_bConnect = true;
		if (m_Client[n].Send(strMsg1, DATA_SIZE) == -1)
		{
			MessageBox(_T("ȯ�� Message ���� ����"));
			m_Client[n].m_bConnect = false;
			m_Client[n].Close();
			return -1;
		}
		sprintf_s(Buf, "%d ��° ������ �Դϴ�.\r\n", n + 1);
		m_Client[n].Send(Buf, DATA_SIZE);
		m_strMsg += Buf;
	}
	else
	{
		m_Client[n].Send(strMsg2, DATA_SIZE);
		m_strMsg += "���� �ο� �ʰ� �Դϴ�.\r\n";
		m_Client[n].Close();
	}
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
}


void CSjEchoServerMultiDlg::OnClickedStartBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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


void CSjEchoServerMultiDlg::OnClickedStopBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfxMessageBox(_T("Server�� �����մϴ�!!"), MB_YESNO) == IDYES)
	{
		m_ctrlStopBt.EnableWindow(FALSE);
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Sever Start"));
		m_Server.ShutDown();
		m_Server.Close();
		for (int i = 0; i < MAX_USER; i++)
		{
			if (m_Client[i].m_bConnect)
				m_Client[i].Close();
		}
		/*for (int i = 0; i < m_nCnt; i++)
		{
			m_Client[i].Close();
		}
		m_nCnt = 0;*/
		m_strMsg += "Server�� �����մϴ�. \r\n";
		UpdateData(FALSE);
	}
}


LRESULT CSjEchoServerMultiDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	char Buf1[100], Buf2[100];
	/*int i;
	for (i = 0; i < MAX_USER; i++)
	{
		if (m_Client[i].m_bReceive)
		{
			m_Client[i].m_bReceive = false;
			break;
		}
	}
	m_Client[i].Receive(Buf2, DATA_SIZE);*/
	CMySocket *pSocket;
	pSocket = (CMySocket *)IParam;
	int recCnt = pSocket->Receive(Buf2, 100);
	/*pSocket->Receive(Buf2, 100);*/
	sprintf_s(Buf1, "Server : %s\r\n", Buf2, DATA_SIZE);
	/*if (pSocket->Send(Buf1, DATA_SIZE) == -1)
	{
		MessageBox(_T("Message ���� ����"));
		return -1;
	}
	sprintf_s(Buf1, "Client : %s\r\n", Buf2, DATA_SIZE);
	*/ // 2��
	/*if (m_Client[i].Send(Buf1, DATA_SIZE) == -1)
	{
		MessageBox(_T("Message ���� ����"));
		return -1;
	}
	sprintf_s(Buf1, "Client(%d��) : %s\r\n", i+1, Buf2, DATA_SIZE);
	*/ // 1��
	/*for (int i = 0; i < m_nCnt; i++)
	{
		if (m_Client[i].Send(Buf1, DATA_SIZE) == -1)
		{
			MessageBox(_T("Message ���� ����"));
			return -1;
		}
	}*/
	for (int i = 0; i < MAX_USER - 1; i++)
	{
		if (m_Client[i].m_bConnect)
		{
			if (m_Client[i].Send(Buf1, DATA_SIZE) == -1)
			{
				m_Client[i].m_bConnect = false;
				m_Client[i].Close();
				sprintf_s(Buf2, "%d �� ����� ����", i + 1);
			}
		}
	}
	sprintf_s(Buf1, "Client : %s\r\n", Buf2, DATA_SIZE);
	m_strMsg += Buf1;
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
}
