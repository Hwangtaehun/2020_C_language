
// SjPuzzleDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjPuzzle.h"
#include "SjPuzzleDlg.h"
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


// CSjPuzzleDlg 대화 상자



CSjPuzzleDlg::CSjPuzzleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjPuzzleDlg::IDD, pParent)
	, m_colCnt(0)
	, m_rowCnt(0)
	, m_moveCnt(0)
	, m_nTime(0)
	, m_strCorect(_T(""))
	, m_bNumber(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nXSize = 0;
	m_nYSize = 0;
}

void CSjPuzzleDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_COL, m_colCnt);
	DDX_Text(pDX, IDC_EDIT_ROW, m_rowCnt);
	DDX_Text(pDX, IDC_EDIT_MOVE, m_moveCnt);
	DDX_Text(pDX, IDC_EDIT_TIME, m_nTime);
	DDX_Text(pDX, IDC_EDIT_CORECT, m_strCorect);
	DDX_Check(pDX, IDC_CHECK_PNUMBER, m_bNumber);
	DDX_Control(pDX, IDC_BT_START, m_ctrlStartBt);
	DDX_Control(pDX, IDC_BT_STOP, m_ctrlStopBt);
}

BEGIN_MESSAGE_MAP(CSjPuzzleDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_START, &CSjPuzzleDlg::OnClickedStartButton)
	ON_BN_CLICKED(IDC_BT_STOP, &CSjPuzzleDlg::OnClickedStopButton)
	ON_BN_CLICKED(IDCANCEL, &CSjPuzzleDlg::OnClickedEndButton)
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK_PNUMBER, &CSjPuzzleDlg::OnClickedShowNumber)
END_MESSAGE_MAP()


// CSjPuzzleDlg 메시지 처리기

BOOL CSjPuzzleDlg::OnInitDialog()
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

void CSjPuzzleDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjPuzzleDlg::OnPaint()
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
HCURSOR CSjPuzzleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjPuzzleDlg::OnClickedStartButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSjPuzzleDlg::OnClickedStopButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSjPuzzleDlg::OnClickedEndButton()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CSjPuzzleDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSjPuzzleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);
}


void CSjPuzzleDlg::OnClickedShowNumber()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CSjPuzzleDlg::InitialData()
{
}


void CSjPuzzleDlg::DrawRectAll()
{
}


void CSjPuzzleDlg::DrawRect(int nX, int nY)
{
}


void CSjPuzzleDlg::DisplayAll()
{
}


void CSjPuzzleDlg::DrawPicture(int nX, int nY, int nPictureNo)
{
}


BOOL CSjPuzzleDlg::CorrectCount()
{
	return 0;
}


void CSjPuzzleDlg::DisplayNumber()
{
}
