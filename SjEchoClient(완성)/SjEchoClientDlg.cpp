
// SjEchoClientDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjEchoClient.h"
#include "SjEchoClientDlg.h"
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


// CSjEchoClientDlg 대화 상자



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


// CSjEchoClientDlg 메시지 처리기

BOOL CSjEchoClientDlg::OnInitDialog()
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

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSjEchoClientDlg::OnPaint()
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
HCURSOR CSjEchoClientDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjEchoClientDlg::OnClickedConnectBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_Socket.Create();
	m_Socket.SetMainWindow(this);
	if (!m_Socket.Connect(m_strIpAddress, m_nPortNo))
	{
		MessageBox(_T("Sever에 접속하지 못했네유 !!"));
		m_Socket.Close();
		return;
	}
	m_ctrlConnectBt.EnableWindow(FALSE);
	m_ctrlConnectBt.SetWindowText(_T("Server연결중"));
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
	}
	/*m_Socket.Close();*/
}


void CSjEchoClientDlg::OnClickedSendBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char buf[100] = "";
	int n;
	UpdateData(TRUE);
	if (!m_strSendData.IsEmpty())
	{
		strcpy_s(buf, 100, CT2A(m_strSendData));
		n = m_Socket.Send(buf, 100);
		if (n == -1)
			MessageBox(_T("전송실패"));
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	AfxMessageBox(_T("WM_RBUTTONDBLCLK 메시지가 도착"));
	char buf[100];
	m_Socket.Receive(buf, 100);
	m_strReceiveData += buf;
	UpdateData(FALSE);
	CDialogEx::OnRButtonDblClk(nFlags, point);
}


LRESULT CSjEchoClientDlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{
	//MessageBox(_T("UM_RECEIVE 메시지 도착"));
	char buf[100];
	m_Socket.Receive(buf, 100);
	m_strReceiveData += buf;
	UpdateData(FALSE);
	m_ctrlReceiveData.LineScroll(m_ctrlReceiveData.GetLineCount(), 0);
	return LRESULT();
}


BOOL CSjEchoClientDlg::PreTranslateMessage(MSG* pMsg)
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
