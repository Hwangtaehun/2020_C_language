
// SjChatClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjChatClient.h"
#include "SjChatClientDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CSjChatClientDlg 대화 상자



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


// CSjChatClientDlg 메시지 처리기

BOOL CSjChatClientDlg::OnInitDialog()
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
	m_ctrlSendBt.EnableWindow(false);
	m_ctrlDisConnectBt.EnableWindow(false);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSjChatClientDlg::OnPaint()
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
HCURSOR CSjChatClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjChatClientDlg::OnClickedDisconnectBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("Sever와의 연결을 끊을까유 !!"), MB_YESNO) == IDYES)
	{
		m_ctrlConnectBt.EnableWindow(TRUE);
		m_ctrlConnectBt.SetWindowText(_T("Server연결"));
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (m_strName.IsEmpty())
	{
		MessageBox(_T("대화명을 입력하세요."));
		return;
	}
	m_Socket.Create();
	m_Socket.SetMainWindow(this);
	if (!m_Socket.Connect(m_strIpAddress, m_nPortNo))
	{
		MessageBox(_T("Sever에 접속하지 못했네유 !!"));
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
	m_ctrlConnectBt.SetWindowText(_T("Server연결중"));
	m_ctrlSendBt.EnableWindow(TRUE);
	m_ctrlDisConnectBt.EnableWindow(TRUE);
	m_ctrlSendData.SetFocus();
	m_bConnect = TRUE;
}


LRESULT CSjChatClientDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	// TODO: 여기에 구현 코드 추가.
	char szReceiveData[DATA_SIZE] = "";
	CString strName;
	m_Socket.Receive((void*)szReceiveData, DATA_SIZE);
	strName = szReceiveData + 1;
	switch (szReceiveData[0])
	{
	case 'i':
		m_strReceiveData += "Server에 접속됨\r\n";
		m_ctrlUserList.AddString(_T("관리자"));
		break;
	case 'U':
		UserList(strName, 'A');
		break;
	case 'C':
		strcat_s(szReceiveData, DATA_SIZE, "님이 접속하셨습니다.\r\n");
		UserList(strName, 'A');
		break;
	case 'E':
		sprintf_s(szReceiveData, "E%s님이 퇴장하셨습니다.\r\n", szReceiveData + 1);
		UserList(strName, 'D');
		break;
	case 'F':
		sprintf_s(szReceiveData, "F%s님이 강제 퇴장하셨습니다.\r\n", szReceiveData + 1);
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
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
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
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char szSendData[DATA_SIZE] = "";
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		// sprintf_s((szSendData + 1), DATA_SIZE - 1, "관리자 : %s\r\n", CT2A(m_strSendData));
		strcpy_s(szSendData + 1, DATA_SIZE - 1, CT2A(m_strSendData));
		szSendData[0] = 'D';
		if(m_Socket.Send((void*)szSendData, DATA_SIZE) == -1)
			MessageBox(_T("전송실패"));
		m_strSendData = "";
		UpdateData(FALSE);
	}
	m_ctrlSendData.SetFocus();
}


void CSjChatClientDlg::UserList(CString strUser, char nFlag)
{
	// TODO: 여기에 구현 코드 추가.
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
