
// SjEchoServerMultiDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjEchoServerMulti.h"
#include "SjEchoServerMultiDlg.h"
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


// CSjEchoServerMultiDlg 대화 상자



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


// CSjEchoServerMultiDlg 메시지 처리기

BOOL CSjEchoServerMultiDlg::OnInitDialog()
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
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSjEchoServerMultiDlg::OnPaint()
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
HCURSOR CSjEchoServerMultiDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



LRESULT CSjEchoServerMultiDlg::OnAcceptMsg(WPARAM wParam, LPARAM IParam)
{
	char strMsg1[DATA_SIZE] = "안녕하세유 지는유 \r\n Echo Server인디유 \r\n";
	char strMsg2[DATA_SIZE] = "접속 인원 초과입니다.\r\n잠시 후 다시 이용해 주세요! \r\n";
	char Buf[DATA_SIZE];
	int n;
	for (n = 0; n < MAX_USER - 1; n++)
	{
		if (!m_Client[n].m_bConnect)
			break;
	}
	if (!m_Server.Accept(m_Client[n]))
	{
		MessageBox(_T("Client 연결 실패"));
		return -1;
	}
	if (n < MAX_USER - 1)
	{
		m_Client[n].SetMainWindow(this);
		m_Client[n].m_bConnect = true;
		if (m_Client[n].Send(strMsg1, DATA_SIZE) == -1)
		{
			MessageBox(_T("환영 Message 전송 실패"));
			m_Client[n].m_bConnect = false;
			m_Client[n].Close();
			return -1;
		}
		sprintf_s(Buf, "%d 번째 접속자 입니다.\r\n", n + 1);
		m_Client[n].Send(Buf, DATA_SIZE);
		m_strMsg += Buf;
	}
	else
	{
		m_Client[n].Send(strMsg2, DATA_SIZE);
		m_strMsg += "접속 인원 초과 입니다.\r\n";
		m_Client[n].Close();
	}
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
}


void CSjEchoServerMultiDlg::OnClickedStartBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	m_ctrlStartBt.EnableWindow(FALSE);
	m_ctrlStartBt.SetWindowText(_T("Server 실행중"));
	if (!m_Server.ServerStart(m_nPortNo))
	{
		MessageBox(_T("Server Socket 문제 발생"));
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStartBt.SetWindowText(_T("Sever Start"));
		return;
	}
	m_ctrlStopBt.EnableWindow(TRUE);
	m_strMsg += "Server 실행 후 대기 중입니다.\r\n";
	UpdateData(FALSE);
}


void CSjEchoServerMultiDlg::OnClickedStopBt()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (AfxMessageBox(_T("Server를 종료합니다!!"), MB_YESNO) == IDYES)
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
		m_strMsg += "Server를 종료합니다. \r\n";
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
		MessageBox(_T("Message 전송 실패"));
		return -1;
	}
	sprintf_s(Buf1, "Client : %s\r\n", Buf2, DATA_SIZE);
	*/ // 2번
	/*if (m_Client[i].Send(Buf1, DATA_SIZE) == -1)
	{
		MessageBox(_T("Message 전송 실패"));
		return -1;
	}
	sprintf_s(Buf1, "Client(%d번) : %s\r\n", i+1, Buf2, DATA_SIZE);
	*/ // 1번
	/*for (int i = 0; i < m_nCnt; i++)
	{
		if (m_Client[i].Send(Buf1, DATA_SIZE) == -1)
		{
			MessageBox(_T("Message 전송 실패"));
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
				sprintf_s(Buf2, "%d 번 사용자 퇴장", i + 1);
			}
		}
	}
	sprintf_s(Buf1, "Client : %s\r\n", Buf2, DATA_SIZE);
	m_strMsg += Buf1;
	UpdateData(FALSE);
	m_ctrlMsg.LineScroll(m_ctrlMsg.GetLineCount(), 0);
	return LRESULT();
}
