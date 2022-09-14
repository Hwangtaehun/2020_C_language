
// SjChatServerDlg.cpp : 구현 파일
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

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CSjChatServerDlg 대화 상자



CSjChatServerDlg::CSjChatServerDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjChatServerDlg::IDD, pParent)
	, m_strUserList(_T(""))
	, m_strIpAddress(_T(""))
	, m_nPortNo(1234)
	, m_strName(_T("관리자"))
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


// CSjChatServerDlg 메시지 처리기

BOOL CSjChatServerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
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
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSjChatServerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSjChatServerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjChatServerDlg::OnClickedStartBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrlSendBt.EnableWindow(FALSE);
	m_ctrlStartBt.SetWindowText(_T("Server 실행중"));
	if (!m_Server.ServerStart(this, m_nPortNo))
	{
		MessageBox(_T("Server Socket 문제 발생"));
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Server Start"));
		return;
	}
}


void CSjChatServerDlg::OnClickedStopBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("Server를 종료합니다!!"), MB_YESNO) == IDYES)
		return;

	CSjClientSocket *pNode;
	char szSendData[DATA_SIZE] = "QServer가 종료 됩니다.";
	POSITION frontPos, pos = m_List.GetHeadPosition();
	while (pos != NULL)
	{
		frontPos = pos;
		pNode = (CSjClientSocket *)m_List.GetNext(pos);
		if (pNode->Send(szSendData, DATA_SIZE) == -1)
			MessageBox(_T("전송실패"));
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
	m_strReceiveData += "Server를 종료합니다.\r\n";
	UpdateData(FALSE);
}


void CSjChatServerDlg::OnClickedSendBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char szSendData[DATA_SIZE] = "";
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		sprintf_s((szSendData + 1), DATA_SIZE - 1, "관리자 : %s\r\n", CT2A(m_strSendData));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char szName[10] = "";
	char szSendData[DATA_SIZE] = "";

	UpdateData(TRUE);
	strcpy_s(szName, 10, CT2A(m_strUserList));
	sprintf_s(szSendData, DATA_SIZE, "F%s", szName);
	UserList(m_strUserList, 'D');
	BroadCast((void*)szSendData);
	m_strReceiveData += szSendData + 1;
	m_strReceiveData += "님이 강제 퇴장 되었습니다.\r\n";
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
		MessageBox(_T("Client 연결 실패"));
		return -1;
	}
	/*szSendData[0] = 'I';
	strcpy_s(szSendData, DATA_SIZE, "ISejong Chatting Server입니다.\r\n");*/
	sprintf_s(szSendData, DATA_SIZE, "ISejong Chatting Server입니다.\r\n");
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
		m_strReceiveData += "님이 접속하셨습니다.\r\n";
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
			MessageBox(_T("전송실패"));
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
	m_strReceiveData += "님이 퇴장하셨습니다.\r\n";
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
