
// SjChatServerDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjChatServer.h"
#include "SjChatServerDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#define ZeroMemory RrlZeroMemory
#define RrlZeroMemory(destionation, Length) memset((Destination), 0, (Length))

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


// CSjChatServerDlg ��ȭ ����



CSjChatServerDlg::CSjChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjChatServerDlg::IDD, pParent)
	, m_strUserList(_T(""))
	, m_strIpAddress(_T(""))
	, m_nPortNo(1234)
	, m_strName(_T("������"))
	, m_strSendData(_T(""))
	, m_strReceiveData(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSjChatServerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_START_BT, m_ctrlStartBt);
	DDX_Control(pDX, IDC_STOP_BT, m_ctrlStopBt);
	DDX_Control(pDX, IDC_SEND_BT, m_ctrlSendBt);
	DDX_Control(pDX, IDC_FORCED_EXIT_BT, m_ctrlForcedBt);
	DDX_Control(pDX, IDC_USER_LIST, m_ctrlUserList);
	DDX_LBString(pDX, IDC_USER_LIST, m_strUserList);
	DDX_Text(pDX, IDC_IP_ADDRESS, m_strIpAddress);
	DDX_Control(pDX, IDC_IP_ADDRESS, m_ctrlIpAddress);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_SEND_DATA, m_strSendData);
	DDX_Control(pDX, IDC_SEND_DATA, m_ctrlSendData);
	DDX_Text(pDX, IDC_RECEIVE_DATA, m_strReceiveData);
	DDX_Control(pDX, IDC_RECEIVE_DATA, m_ctrlReceiveData);
}

BEGIN_MESSAGE_MAP(CSjChatServerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START_BT, &CSjChatServerDlg::OnClickedStartBt)
	ON_BN_CLICKED(IDC_STOP_BT, &CSjChatServerDlg::OnClickedStopBt)
	ON_BN_CLICKED(IDC_SEND_BT, &CSjChatServerDlg::OnClickedSendBt)
	ON_BN_CLICKED(IDC_FORCED_EXIT_BT, &CSjChatServerDlg::OnClickedForcedExitBt)
	ON_MESSAGE(UM_ACCEPT, &CSjChatServerDlg::OnAcceptMsg)
	ON_MESSAGE(UM_RECEIVE, &CSjChatServerDlg::OnReceiveMsg)
	ON_MESSAGE(UM_SOCKET_CLOSE, &CSjChatServerDlg::OnCloseMsg)
END_MESSAGE_MAP()


// CSjChatServerDlg �޽��� ó����

BOOL CSjChatServerDlg::OnInitDialog()
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
	char hostName[32];
	struct in_addr myIpAddr;
	HOSTENT * pHostEnt = NULL;
	gethostname(hostName, sizeof(hostName));
	pHostEnt = gethostbyname(hostName);
	myIpAddr.S_un.S_addr = *(u_long*)(pHostEnt->h_addr_list[0]);
	m_strIpAddress = inet_ntoa(myIpAddr);
	UpdateData(FALSE);
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	m_ctrlForcedBt.EnableWindow(FALSE);
	m_ctrlSendBt.EnableWindow(FALSE);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

void CSjChatServerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjChatServerDlg::OnPaint()
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
HCURSOR CSjChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjChatServerDlg::OnClickedStartBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	m_ctrlSendBt.EnableWindow(FALSE);
	m_ctrlStartBt.SetWindowText(_T("Server ������"));
	if (!m_Server.ServerStart(this, m_nPortNo))
	{
		MessageBox(_T("Server Socket ���� �߻�"));
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Server Start"));
		return;
	}
}


void CSjChatServerDlg::OnClickedStopBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (AfxMessageBox(_T("Server�� �����մϴ�!!"), MB_YESNO) == IDYES)
		return;

	CSjClientSocket *pNode;
	char szSendData[DATA_SIZE] = "QServer�� ���� �˴ϴ�.";
	POSITION frontPos, pos = m_List.GetHeadPosition();
	while (pos != NULL)
	{
		frontPos = pos;
		pNode = (CSjClientSocket *)m_List.GetNext(pos);
		if (pNode->Send(szSendData, DATA_SIZE) == -1)
			MessageBox(_T("���۽���"));
		m_List.RemoveAt(frontPos);
		pNode->Close();
		delete pNode;
	}
	m_ctrlUserList.ResetContent();

	m_ctrlForcedBt.EnableWindow(false);
	m_ctrlSendBt.EnableWindow(false);
	m_ctrlStopBt.EnableWindow(false);
	m_ctrlStartBt.EnableWindow(true);
	m_ctrlStartBt.SetWindowText(_T("Server Start"));
	m_Server.ShutDown();
	m_Server.Close();
	m_strReceiveData += "Server�� �����մϴ�.\r\n";
	UpdateData(FALSE);
}


void CSjChatServerDlg::OnClickedSendBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char szSendData[DATA_SIZE] = "";
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		sprintf_s((szSendData + 1), DATA_SIZE - 1, "������ : %s\r\n", CT2A(m_strSendData));
		szSendData[0] = 'D';
		BroadCast((void *)szSendData);
		m_strReceiveData += szSendData + 1;
		m_strSendData = "";
		UpdateData(FALSE);
	}
	m_ctrlSendData.SetFocus();
}


void CSjChatServerDlg::OnClickedForcedExitBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	char szName[10] = "";
	char szSendData[DATA_SIZE] = "";

	UpdateData(TRUE);
	strcpy_s(szName, 10, CT2A(m_strUserList));
	sprintf_s(szSendData, DATA_SIZE, "F%s", szName);
	UserList(m_strUserList, 'D');
	BroadCast((void*)szSendData);
	m_strReceiveData += szSendData + 1;
	m_strReceiveData += "���� ���� ���� �Ǿ����ϴ�.\r\n";
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);

	CSjClientSocket* pNode;
	POSITION frontPos, pos = m_List.GetHeadPosition();
	while (pos != NULL)
	{
		frontPos = pos;
		pNode = (CSjClientSocket*)m_List.GetNext(pos);
		if (pNode->m_strName == m_strUserList)
		{
			m_List.RemoveAt(frontPos);
			pNode->Close();
			delete pNode;
			break;
		}
	}
}


LRESULT CSjChatServerDlg::OnAcceptMsg(WPARAM wParam, LPARAM IParam)
{
	char szSendData[DATA_SIZE] = "", szReceiveData[DATA_SIZE] = "";
	CSjClientSocket *pSocket = new CSjClientSocket;
	if (!m_Server.Accept(*pSocket))
	{
		MessageBox(_T("Client ���� ����"));
		return -1;
	}
	/*szSendData[0] = 'I';
	strcpy_s(szSendData, DATA_SIZE, "ISejong Chatting Server�Դϴ�.\r\n");*/
	sprintf_s(szSendData, DATA_SIZE, "ISejong Chatting Server�Դϴ�.\r\n");
	pSocket->Send((void *)szSendData, DATA_SIZE);
	pSocket->SetMainWindow(this);
	m_List.AddTail(pSocket);
	return LRESULT();
}


LRESULT CSjChatServerDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	char szSendData[DATA_SIZE] = "", szReceiveData[DATA_SIZE] = "";
	CString strName;
	char szName[20];

	CSjClientSocket *pSocket = (CSjClientSocket *)IParam;
	pSocket->Receive((void *)szReceiveData, DATA_SIZE);

	switch (szReceiveData[0])
	{
	case 'N':
		szSendData[0] = 'U';
		for (int i = 0; i < m_ctrlUserList.GetCount(); i++)
		{
			m_ctrlUserList.GetText(i, strName);
			sprintf_s(szSendData, DATA_SIZE, "U%s", CT2A(strName));
			pSocket->Send((void *)szSendData, DATA_SIZE);
		}
		pSocket->m_strName = szReceiveData + 1;
		//szSendData[0] = 'C';
		sprintf_s(szSendData, DATA_SIZE, "C%s", szReceiveData + 1);
		BroadCast((void *)szSendData);
		UserList(pSocket->m_strName, 'A');
		m_strReceiveData += szReceiveData + 1;
		m_strReceiveData += "���� �����ϼ̽��ϴ�.\r\n";
		break;
	default:
		strcpy_s(szName, 20, CT2A(pSocket->m_strName));
		sprintf_s(szSendData, "D%s : %s \r\n", szName, szReceiveData + 1);
		BroadCast((void *)szSendData);
		m_strReceiveData += szSendData + 1;
	}
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);
	return LRESULT();
}


bool CSjChatServerDlg::BroadCast(void * pStr)
{
	CSjClientSocket *pNode;
	for (POSITION pos = m_List.GetHeadPosition(); pos != NULL; )
	{
		pNode = (CSjClientSocket *)m_List.GetNext(pos);
		if (pNode->Send(pStr, DATA_SIZE) == -1)
			MessageBox(_T("���۽���"));
	}
	return false;
}


LRESULT CSjChatServerDlg::OnCloseMsg(WPARAM wParam, LPARAM IParam)
{
	char szName[20] = "";
	char szSendData[DATA_SIZE] = "";

	CSjClientSocket* pSocket = (CSjClientSocket*)IParam;
	strcpy_s(szName, 10, CT2A(pSocket->m_strName));
	sprintf_s(szSendData, DATA_SIZE, "E%s", szName);

	UserList(pSocket->m_strName, 'D');

	BroadCast((void*)szSendData);
	m_strReceiveData += szSendData + 1;
	m_strReceiveData += "���� �����ϼ̽��ϴ�.\r\n";
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);

	CSjClientSocket* pNode;
	POSITION frontPos, pos = m_List.GetHeadPosition();
	while (pos != NULL)
	{
		frontPos = pos;
		pNode = (CSjClientSocket*)m_List.GetNext(pos);
		if (pSocket == pNode)
		{
			m_List.RemoveAt(frontPos);
			pSocket->Close();
			delete pSocket;
			break;
		}
	}
	return LRESULT();
}


void CSjChatServerDlg::UserList(CString strUser, char nFlag)
{
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
