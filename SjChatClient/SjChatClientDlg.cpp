
// SjChatClientDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjChatClient.h"
#include "SjChatClientDlg.h"
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


// CSjChatClientDlg ��ȭ ����



CSjChatClientDlg::CSjChatClientDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjChatClientDlg::IDD, pParent)
	, m_strIpAddress(_T(""))
	, m_nPortNo(1234)
	, m_strSendData(_T(""))
	, m_strReceiveData(_T(""))
	, m_strName(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSjChatClientDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_CONNECT_BT, m_ctrlConnectBt);
	DDX_Control(pDX, IDC_DISCONNECT_BT, m_ctrlDisConnectBt);
	DDX_Control(pDX, IDC_SEND_BT, m_ctrlSendBt);
	DDX_Control(pDX, IDC_IP_ADDRESS, m_ctrlIpAddress);
	DDX_Text(pDX, IDC_IP_ADDRESS, m_strIpAddress);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDX_Text(pDX, IDC_SEND_DATA, m_strSendData);
	DDX_Control(pDX, IDC_SEND_DATA, m_ctrlSendData);
	DDX_Control(pDX, IDC_RECEIVE_DATA, m_ctrlReceiveData);
	DDX_Text(pDX, IDC_RECEIVE_DATA, m_strReceiveData);
	DDX_Control(pDX, IDC_NAME, m_ctrlName);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Control(pDX, IDC_USER_LIST, m_ctrlUserList);
}

BEGIN_MESSAGE_MAP(CSjChatClientDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DISCONNECT_BT, &CSjChatClientDlg::OnClickedDisconnectBt)
	ON_BN_CLICKED(IDC_CONNECT_BT, &CSjChatClientDlg::OnClickedConnectBt)
	ON_BN_CLICKED(IDC_SEND_BT, &CSjChatClientDlg::OnClickedSendBt)
	ON_MESSAGE(UM_RECEIVE, &CSjChatClientDlg::OnReceiveMsg)
END_MESSAGE_MAP()


// CSjChatClientDlg �޽��� ó����

BOOL CSjChatClientDlg::OnInitDialog()
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
	m_ctrlSendBt.EnableWindow(false);
	m_ctrlDisConnectBt.EnableWindow(false);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSjChatClientDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjChatClientDlg::OnPaint()
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
HCURSOR CSjChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjChatClientDlg::OnClickedDisconnectBt()
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
		m_ctrlUserList.ResetContent();
		m_strReceiveData = "";
		UpdateData(FALSE);
	}
}


void CSjChatClientDlg::OnClickedConnectBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	if (m_strName.IsEmpty())
	{
		MessageBox(_T("��ȭ���� �Է��ϼ���."));
		return;
	}
	m_Socket.Create();
	m_Socket.SetMainWindow(this);
	if (!m_Socket.Connect(m_strIpAddress, m_nPortNo))
	{
		MessageBox(_T("Sever�� �������� ���߳��� !!"));
		m_Socket.Close();
		return;
	}
	char szSendData[DATA_SIZE] = "";
	char szName[20];
	strcpy_s(szName, 20, CT2A(m_strName));
	//szSendData[0] = 'N';
	sprintf_s(szSendData, "N%s", szName);
	m_Socket.Send(szSendData, DATA_SIZE);

	m_ctrlConnectBt.EnableWindow(FALSE);
	m_ctrlConnectBt.SetWindowText(_T("Server������"));
	m_ctrlSendBt.EnableWindow(TRUE);
	m_ctrlDisConnectBt.EnableWindow(TRUE);
	m_ctrlSendData.SetFocus();
	m_bConnect = TRUE;
}


LRESULT CSjChatClientDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	char szReceiveData[DATA_SIZE] = "";
	CString strName;
	m_Socket.Receive((void*)szReceiveData, DATA_SIZE);
	strName = szReceiveData + 1;
	switch (szReceiveData[0])
	{
	case 'i':
		m_strReceiveData += "Server�� ���ӵ�\r\n";
		m_ctrlUserList.AddString(_T("������"));
		break;
	case 'U':
		UserList(strName, 'A');
		break;
	case 'C':
		strcat_s(szReceiveData, DATA_SIZE, "���� �����ϼ̽��ϴ�.\r\n");
		UserList(strName, 'A');
		break;
	case 'E':
		sprintf_s(szReceiveData, "E%s���� �����ϼ̽��ϴ�.\r\n", szReceiveData + 1);
		UserList(strName, 'D');
		break;
	case 'F':
		sprintf_s(szReceiveData, "F%s���� ���� �����ϼ̽��ϴ�.\r\n", szReceiveData + 1);
		UserList(strName, 'D');
		break;
	case 'Q':
		m_ctrlUserList.ResetContent();
		break;
	}
	m_strReceiveData += szReceiveData + 1;
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);
	return LRESULT();
}


BOOL CSjChatClientDlg::PreTranslateMessage(MSG* pMsg)
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


void CSjChatClientDlg::OnClickedSendBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char szSendData[DATA_SIZE] = "";
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		// sprintf_s((szSendData + 1), DATA_SIZE - 1, "������ : %s\r\n", CT2A(m_strSendData));
		strcpy_s(szSendData + 1, DATA_SIZE - 1, CT2A(m_strSendData));
		szSendData[0] = 'D';
		if(m_Socket.Send((void*)szSendData, DATA_SIZE) == -1)
			MessageBox(_T("���۽���"));
		m_strSendData = "";
		UpdateData(FALSE);
	}
	m_ctrlSendData.SetFocus();
}


void CSjChatClientDlg::UserList(CString strUser, char nFlag)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int n, loc;
	if (nFlag == 'D')
	{
		n = m_ctrlUserList.FindString(-1, strUser);
		m_ctrlUserList.DeleteString(n);
	}
	else if (nFlag == 'A')
	{
		m_ctrlUserList.AddString(strUser);
	}
	loc = m_ctrlUserList.GetCount();
	m_ctrlUserList.SetAnchorIndex(loc - 1);
	m_ctrlUserList.SetCurSel(loc - 1);
}
