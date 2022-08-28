
// SejongMineDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SejongMine.h"
#include "SejongMineDlg.h"
#include "afxdialogex.h"
#include "CustomDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

struct LastData
{
	UINT Difficulty;
	int Width;
	int Height;
	int Mines;
	int Xpos;
	int Ypos;
} IData = { 0 };

struct RandData
{
	int Time;
	char Name[20];
} rData[3][3] = { 0 };

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


// CSejongMineDlg 대화 상자



CSejongMineDlg::CSejongMineDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSejongMineDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nBoxCntX = 8;
	m_nBoxCntY = 8;
	m_nMineCnt = 10;
	m_nMine = 0;
	m_nTime = 0;
	m_nOpened = 0;
	m_nGameState = 0;
	m_nFace = 0;
	m_nld = IDM_BEGINNER;
	m_bFirst = TRUE;
}

void CSejongMineDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CSejongMineDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_COMMAND(IDM_BEGINNER, &CSejongMineDlg::OnBeginner)
	ON_COMMAND(IDM_INTERMEDIATE, &CSejongMineDlg::OnIntermediate)
	ON_COMMAND(IDM_EXPERIENCE, &CSejongMineDlg::OnExperience)
	ON_COMMAND(IDM_CUSTOM, &CSejongMineDlg::OnCustom)
	ON_COMMAND(IDM_START, &CSejongMineDlg::OnStart)
	ON_WM_LBUTTONDOWN()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_WM_RBUTTONDOWN()
	ON_WM_RBUTTONUP()
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CSejongMineDlg 메시지 처리기

BOOL CSejongMineDlg::OnInitDialog()
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
	m_pDC = GetDC();
	m_bmBox.LoadBitmap(IDB_BOX);
	m_bmNumber.LoadBitmap(IDB_NUMBER);
	m_bmFace.LoadBitmap(IDB_FACE);

	m_boxDC.CreateCompatibleDC(m_pDC);
	m_numberDC.CreateCompatibleDC(m_pDC);
	m_faceDC.CreateCompatibleDC(m_pDC);

	m_boxDC.SelectObject(&m_bmBox);
	m_numberDC.SelectObject(&m_bmNumber);
	m_faceDC.SelectObject(&m_bmFace);

	CFile file;
	if (file.Open(_T("SejongMine.dat"), CFile::modeRead))
	{
		file.Read((void*)&IData, sizeof(IData));
		m_nld = IData.Difficulty;
		m_nBoxCntX = IData.Width;
		m_nBoxCntY = IData.Height;
		m_nMineCnt = IData.Mines;
		file.Close();
	}
	else
		OnBeginner();
	ResizeWindow();
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSejongMineDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSejongMineDlg::OnPaint()
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
		CRect rect;
		int x, y;
		GetClientRect(rect);
		for (x = 0; x < 3; x++)
		{
			m_pDC->Draw3dRect(rect.left + x, rect.top + x, rect.right - x * 2, rect.bottom - x * 2, RGB(255, 255, 255), RGB(128, 128, 128));
		}
		for (x = 0; x < 2; x++)
		{
			m_pDC->Draw3dRect(rect.left + x + 10, rect.top + x + 10, rect.Width() - (10 + x) * 2, 34 - x * 2, RGB(128, 128, 128), RGB(255, 255, 255));;
			m_pDC->Draw3dRect(rect.left + x + 10, rect.top + x + 52, rect.Width() - (10 + x) * 2, rect.Height() - 60 - x * 2, RGB(128, 128, 128), RGB(255, 255, 255));
		}
		for (x = 0; x < m_nBoxCntX; x++)
		{
			for (y = 0; y < m_nBoxCntY; y++)
			{
				DrawBox(x, y, m_BoxStyle[y][x]);
			}
		}
		DrawFace(m_nFace);
		DrawMineCounter();
		DrawTimer();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSejongMineDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSejongMineDlg::ResizeWindow()
{
	// TODO: 여기에 구현 코드 추가.
	int nXsize, nYsize, nWidth, nHeight;
	nXsize = (GetSystemMetrics(SM_CXSCREEN));
	nYsize = (GetSystemMetrics(SM_CYSCREEN));
	nWidth = m_nBoxCntX * 16 + 42;
	nHeight = m_nBoxCntY * 16 + 125;

	if (m_bFirst)
	{
		if (IData.Mines == 0)
		{
			m_WndRect.left = nXsize / 5;
			m_WndRect.top = nYsize / 5;
		}
		else
		{
			m_WndRect.left = IData.Xpos;
			m_WndRect.top = IData.Ypos;
		}
		m_bFirst = FALSE;
	}
	else
	{
		GetWindowRect(&m_WndRect);
		if (nXsize < m_WndRect.left + nWidth)
			m_WndRect.left = nXsize - nWidth;
		if (nYsize < m_WndRect.top + nHeight)
			m_WndRect.top = nYsize - nHeight;
	}

	m_WndRect.right = m_WndRect.left + nWidth;
	m_WndRect.bottom = m_WndRect.top + nHeight;
	MoveWindow(m_WndRect);

	m_WndRect.left = BOX_START_X;
	m_WndRect.top = BOX_START_Y;
	m_WndRect.right = m_WndRect.left + m_nBoxCntX * 16;
	m_WndRect.bottom = m_WndRect.top + m_nBoxCntY * 16;

	m_FaceRect.left = m_nBoxCntX / 2 * 16;
	m_FaceRect.top = 16;
	m_FaceRect.right = m_nBoxCntX / 2 * 16 + 24;
	m_FaceRect.bottom = 16 + 24;
	Invalidate();
	InitGame();
}


void CSejongMineDlg::DrawBox(int x, int y, int style)
{
	// TODO: 여기에 구현 코드 추가.
	m_pDC->BitBlt(x * 16 + BOX_START_X, y * 16 + BOX_START_Y, 16, 16, &m_boxDC, 0, style * 16, SRCCOPY);
}


void CSejongMineDlg::DrawFace(int style)
{
	// TODO: 여기에 구현 코드 추가.
	m_pDC->BitBlt(m_FaceRect.left, m_FaceRect.top, 24, 24, &m_faceDC, 0, style * 24, SRCCOPY);
}


void CSejongMineDlg::DrawMineCounter()
{
	// TODO: 여기에 구현 코드 추가.
	int i = 0, num, su = 100, nMineCnt = m_nMine;
	nMineCnt = abs(nMineCnt);
	for (i = 0; i < 3; i++)
	{
		if (i == 2 && m_nMine < 0)
			num = 10;
		else
			num = nMineCnt % 10;
		m_pDC->BitBlt(BOX_START_X + (3 - i) * 13 - 8, 16, 13, 23, &m_numberDC, 0, num * 23, SRCCOPY);
		nMineCnt /= 10;
	}
	m_pDC->Draw3dRect(BOX_START_X + 4, 15, 13 * 3, 25, RGB(128, 128, 128), RGB(255, 255, 255));
}


void CSejongMineDlg::DrawTimer()
{
	// TODO: 여기에 구현 코드 추가.
	int nTimer = m_nTime;
	for (int i = 0; i < 3; i++)
	{
		m_pDC->BitBlt(BOX_START_X + m_nBoxCntX * 16 - 20 - i * 13, 16, 13, 23, &m_numberDC, 0, nTimer % 10 * 23, SRCCOPY);
		nTimer /= 10;
	}
	m_pDC->Draw3dRect(BOX_START_X + m_nBoxCntX * 16 - 3 * 13 - 8, 15, 13 * 3 + 3, 25, RGB(128, 128, 128), RGB(255, 255, 255));
}


void CSejongMineDlg::InitGame()
{
	// TODO: 여기에 구현 코드 추가.
	if (m_bTimerState)
	{
		KillTimer(0);
		m_bTimerState = FALSE;
	}
	m_nTime = 0;
	m_nFace = 0;
	m_nGameState = 0;
	m_bLbuttonDown = m_bRbuttonDown = FALSE;
	m_nMine = m_nMineCnt;
	m_nOpened = m_nBoxCntX * m_nBoxCntY - m_nMineCnt;
	memset((void*)m_BoxState, 0, sizeof(m_BoxState));
	memset((void*)m_BoxStyle, 0, sizeof(m_BoxStyle));
}


void CSejongMineDlg::MineSetting(int dx, int dy)
{
	// TODO: 여기에 구현 코드 추가.
}


int CSejongMineDlg::CountMines(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.
	return 0;
}


void CSejongMineDlg::LRButtonClick(int x, int y, bool bStyle)
{
	// TODO: 여기에 구현 코드 추가.
}


void CSejongMineDlg::ClickBox(int x, int y)
{
	// TODO: 여기에 구현 코드 추가.
}


void CSejongMineDlg::GameWin()
{
	// TODO: 여기에 구현 코드 추가.
}


void CSejongMineDlg::GameLose()
{
	// TODO: 여기에 구현 코드 추가.
}


void CSejongMineDlg::WriteFile()
{
	// TODO: 여기에 구현 코드 추가.
}


BOOL CSejongMineDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.

	return CDialogEx::PreTranslateMessage(pMsg);
}


void CSejongMineDlg::OnBeginner()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nBoxCntX = 8;
	m_nBoxCntY = 8;
	m_nMineCnt = 10;
	m_nld = GetCurrentMessage()->wParam;
	ResizeWindow();
}


void CSejongMineDlg::OnIntermediate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nBoxCntX = 16;
	m_nBoxCntY = 16;
	m_nMineCnt = 40;
	m_nld = GetCurrentMessage()->wParam;
	ResizeWindow();
}


void CSejongMineDlg::OnExperience()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_nBoxCntX = 30;
	m_nBoxCntY = 16;
	m_nMineCnt = 99;
	m_nld = GetCurrentMessage()->wParam;
	ResizeWindow();
}


void CSejongMineDlg::OnCustom()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	CustomDlg dlg;
	dlg.m_nWidth = m_nBoxCntX;
	dlg.m_nHeight = m_nBoxCntY;
	dlg.m_nMine = m_nMineCnt;
	if (dlg.DoModal() == IDOK)
	{
		m_nBoxCntX = dlg.m_nWidth;
		m_nBoxCntY = dlg.m_nHeight;
		int cnt = m_nBoxCntX * m_nBoxCntY * 8 / 10;
		if (dlg.m_nMine < 10)
			m_nMineCnt = 10;
		else if (dlg.m_nMine > cnt)
			m_nMineCnt = cnt;
		else
			m_nMineCnt = dlg.m_nMine;
		m_nld = GetCurrentMessage()->wParam;
		ResizeWindow();
	}
}


void CSejongMineDlg::OnStart()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	InitGame();
	InvalidateRect(m_WndRect, FALSE);
}


void CSejongMineDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSejongMineDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnLButtonUp(nFlags, point);
}


void CSejongMineDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnMouseMove(nFlags, point);
}


void CSejongMineDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnRButtonDown(nFlags, point);
}


void CSejongMineDlg::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnRButtonUp(nFlags, point);
}


void CSejongMineDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	CDialogEx::OnTimer(nIDEvent);
}


void CSejongMineDlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.
}
