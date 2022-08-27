
// SjTetris1Dlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "SjTetris1.h"
#include "SjTetris1Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

POINT Pattern[7][16] =
{
	{ { 0, 0 }, { 0, -1 }, { -1, 0 }, { -1, -1 }, { 0, 0 }, { 0, -1 }, { -1, 0 }, { -1, -1 }, { 0, 0 }, { 0, -1 }, { -1, 0 }, { -1, -1 }, { 0, 0 }, { 0, -1 }, { -1, 0 }, { -1, -1 } },
	{ { 0, 0 }, { 1, 0 }, { -1, 0 }, { -2, 0 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, -1 }, { 0, 0 }, { 1, 0 }, { -1, 0 }, { -2, 0 }, { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, -1 } },
	{ { 0, 0 }, { -1, 0 }, { 0, -1 }, { 1, -1 }, { 0, 0 }, { 0, 1 }, { -1, 0 }, { -1, -1 }, { 0, 0 }, { -1, 0 }, { 0, -1 }, { 1, -1 }, { 0, 0 }, { 0, 1 }, { -1, 0 }, { -1, -1 } },
	{ { 0, 0 }, { -1, -1 }, { 0, -1 }, { 1, 0 }, { 0, 0 }, { -1, 0 }, { -1, 1 }, { 0, -1 }, { 0, 0 }, { -1, -1 }, { 0, -1 }, { 1, 0 }, { 0, 0 }, { -1, 0 }, { -1, 1 }, { 0, -1 } },
	{ { -1, 0 }, { -1, 1 }, { 0, 1 }, { 1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 1, -1 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 0, -1 }, { -1, -1 }, { -1, 0 }, { -1, 1 } },
	{ { -1, 1 }, { 0, 1 }, { 1, 1 }, { 1, 0 }, { 0, -1 }, { 1, -1 }, { 1, 0 }, { 1, 1 }, { -1, 0 }, { -1, -1 }, { 0, -1 }, { 1, -1 }, { -1, 1 }, { -1, 0 }, { -1, -1 }, { 0, 1 } },
	{ { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, 1 }, { 0, 0 }, { 0, -1 }, { 0, 1 }, { 1, 0 }, { 0, 0 }, { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 0 }, { -1, 0 }, { 0, -1 }, { 0, 1 } }
};

POINT nextPattern[7][4] =
{
	{{-1, 0}, {0, 0}, {-1, 1}, {0, 1}},
	{{-1, 1}, {0, 1}, {1, 1}, {-2, 1}},
	{{0, 1}, {-1, 1}, {0, 0}, {1, 0}},
	{{0, 1}, {-1, 0}, {0, 0}, {1, 1}},
	{{-1, 1}, {-1, 0}, {0, 1}, {1, 1}},
	{{1, 1}, {0, 1}, {-1, 1}, {1, 0}},
	{{0, 1}, {-1, 1}, {1, 1}, {0, 0}}
};

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


// CSjTetris1Dlg 대화 상자



CSjTetris1Dlg::CSjTetris1Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjTetris1Dlg::IDD, pParent)
	, m_nScore(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nX = COL_CNT / 2;
	m_nY = 0;
	m_nPattern = 0;
	m_nRot = 0;
	m_bStart = FALSE;
	m_nBitType = 1;
	m_nNextPattern = 0;
	m_nScore = 0;

	m_mainRect.left = START_X;
	m_mainRect.top = START_Y;
	m_mainRect.right = START_X + BLOCK_SIZE * COL_CNT + 4;
	m_mainRect.bottom = START_Y + BLOCK_SIZE * ROW_CNT + 4;

	m_nextRect.left = START_X + BLOCK_SIZE * COL_CNT + 20;
	m_nextRect.top = START_Y + 30;
	m_nextRect.right = m_nextRect.left + 130;
	m_nextRect.bottom = m_nextRect.top + 80;

	m_mainRect2.left = m_nextRect.right + 35;
	m_mainRect2.top = START_Y;
	m_mainRect2.right = m_mainRect2.left + BLOCK_SIZE * COL_CNT / 2 + 4;
	m_mainRect2.bottom = START_Y + BLOCK_SIZE * ROW_CNT / 2 + 4;
}

void CSjTetris1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_START, m_ctrlStartBt);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_ctrlStopBt);
	DDX_Text(pDX, IDC_EDIT_SCORE, m_nScore);
}

BEGIN_MESSAGE_MAP(CSjTetris1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CSjTetris1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CSjTetris1Dlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CSjTetris1Dlg::OnBnClickedButtonExit)
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CSjTetris1Dlg 메시지 처리기

BOOL CSjTetris1Dlg::OnInitDialog()
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
	MoveWindow(100, 100, m_mainRect.right * 2 + 320, m_mainRect.bottom + 160);
	m_pDC = GetDC();
	m_bmBlock.LoadBitmap(IDB_BLOCK);
	m_BlockDC.CreateCompatibleDC(m_pDC);
	m_BlockDC.SelectObject(&m_bmBlock);
	m_bmBack.LoadBitmap(IDB_BACKGROUND);
	m_BackDC.CreateCompatibleDC(m_pDC);
	m_BackDC.SelectObject(&m_bmBack);

	srand((unsigned)time(NULL));
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	memset((void*)m_Table, -1, sizeof(m_Table));
	memset((void*)m_Table2, -1, sizeof(m_Table2));
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSjTetris1Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CSjTetris1Dlg::OnPaint()
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
		DrawScr();
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSjTetris1Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjTetris1Dlg::DrawScr()
{
	int row, col;
	m_pDC->Rectangle(m_mainRect);
	m_pDC->Rectangle(m_nextRect);
	for (row = 0; row < ROW_CNT; row++)
	{
		for (col = 0; col < COL_CNT; col++)
		{
			if (m_Table[0][row][col] == -1)
			{
				m_pDC->BitBlt(START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, &m_BackDC, col * BLOCK_SIZE, row *BLOCK_SIZE, SRCCOPY);
			}
			else
			{
				m_pDC->BitBlt(START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, &m_BlockDC,
					m_Table[0][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
			}
		}
	}
	DrawScr2();
	m_nScore += 10;
	NextBlock(m_bStart);
}


void CSjTetris1Dlg::InitialGame()
{
	memset((void *)m_Table, -1, sizeof(m_Table));
	DrawScr();
	m_nPattern = rand() % 7;
	m_nRot = 0;
	m_nY = 1;
	m_nX = COL_CNT / 2;
	m_bStart = TRUE;
	DrawBlock(TRUE);

	m_nNextPattern = rand() % 7;
	NextBlock(TRUE);
	SetTimer(1, 500, NULL);
}


void CSjTetris1Dlg::DrawBlock(bool bFlag)
{
	for (int i = 0; i < 4; i++)
	{
		if (bFlag)
		{
			m_pDC->BitBlt(START_X + 2 + (m_nX + Pattern[m_nPattern][i + m_nRot * 4].x) * BLOCK_SIZE,
				START_Y + 2 + (m_nY + Pattern[m_nPattern][i + m_nRot * 4].y) * BLOCK_SIZE,
				BLOCK_SIZE, BLOCK_SIZE, &m_BlockDC, m_nPattern * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
		}
		else
		{
			m_pDC->BitBlt(START_X + 2 + (m_nX + Pattern[m_nPattern][i + m_nRot * 4].x) * BLOCK_SIZE,
				START_Y + 2 + (m_nY + Pattern[m_nPattern][i + m_nRot * 4].y) * BLOCK_SIZE,
				BLOCK_SIZE, BLOCK_SIZE, &m_BackDC, (m_nX + Pattern[m_nPattern][i + m_nRot * 4].x) * BLOCK_SIZE, (m_nY + Pattern[m_nPattern][i + m_nRot * 4].y) * BLOCK_SIZE, SRCCOPY);
		}
	}
}


BOOL CSjTetris1Dlg::BlockDown()
{
	if (!IsAround(m_nX, m_nY + 1))
	{
		SetTable();
		return FALSE;
	}
	DrawBlock(FALSE);
	m_nY++;
	DrawBlock(TRUE);
	return TRUE;
}


BOOL CSjTetris1Dlg::IsAround(int nX, int nY)
{
	int i, row, col;
	for (i = 0; i < 4; i++)
	{
		col = nX + Pattern[m_nPattern][i + m_nRot * 4].x;
		row = nY + Pattern[m_nPattern][i + m_nRot * 4].y;
		if (col < 0 || col > COL_CNT - 1 || row < 1 || row > ROW_CNT - 1)
		{
			return FALSE;
		}
		for (int n = 0; n < 6; n++)
		{
			if (m_Table[n][row][col] != -1)
			{
				return FALSE;
			}
		}
	}
	return TRUE;
}


void CSjTetris1Dlg::SetTable()
{
	int i, row, col, sw;
	for (i = 0; i < 4; i++)
	{
		m_Table[0][m_nY + Pattern[m_nPattern][i + m_nRot * 4].y][m_nX + Pattern[m_nPattern][i + m_nRot * 4].x] = m_nPattern;
	}
	for (row = ROW_CNT - 1; row >= 0; row--)
	{
		sw = 0;
		for (col = 0; col < COL_CNT; col++)
		{
			if (m_Table[0][row][col] == -1)
				sw = -1;
		}
		if (sw == 0)
		{
			for (i = row; i > 0; i--)
			{
				for (col = 0; col < COL_CNT; col++)
				{
					m_Table[0][i][col] = m_Table[0][i - 1][col];
				}
			}
			for (col = 0; col < COL_CNT; col++)
			{
				m_pDC->BitBlt(START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, &m_BackDC, 0, 0, SRCCOPY);
				Sleep(20);
			}
			UpdateData(TRUE);
			m_nScore += 10;
			UpdateData(FALSE);
			DrawScr();
			Sleep(100);
			row++;
		}
	}
	//for (int i = 1; i < 6; i++)
	//{
	//	for (row = 0; row < ROW_CNT; row++)
	//	{
	//		for (col = 0; col < COL_CNT; col++)
	//		{
	//			m_Table[i][row][col] = m_Table[0][row][col];
	//		}
	//	}
	//}
	for (int i = 1; i < 6; i++)
	{
		memcpy((void*)m_Table[i], (void*)m_Table[0], COL_CNT * ROW_CNT);
	}
	DrawScr2();
	m_nX = COL_CNT / 2;
	m_nY = 1;
	m_nPattern = m_nNextPattern;
	NextBlock(FALSE);
	m_nNextPattern = rand() % 7;
	NextBlock(TRUE);
	//m_nPattern = rand() % 7;
	m_nRot = 1;
	if (!IsAround(m_nX, m_nY + 1))
	{
		KillTimer(1);
		MessageBox(_T("으악"));
		m_ctrlStartBt.EnableWindow(TRUE);
		m_ctrlStopBt.EnableWindow(FALSE);
		return;
	}
}


void CSjTetris1Dlg::RolateBlock(bool bFlag)
{
	int nRot = m_nRot;
	DrawBlock(FALSE);
	if (++m_nRot > 3)
		m_nRot = 0;
	if (!IsAround(m_nX, m_nY))
		m_nRot = nRot;
	DrawBlock(TRUE);
}


void CSjTetris1Dlg::MoveDown()
{
	while (BlockDown())
	{
		Sleep(30);
	}
}


void CSjTetris1Dlg::MoveRight()
{
	if (!IsAround(m_nX + 1, m_nY))
		return;
	DrawBlock(FALSE);
	m_nX++;
	DrawBlock(TRUE);
}


void CSjTetris1Dlg::MoveLeft()
{
	if (!IsAround(m_nX - 1, m_nY))
		return;
	DrawBlock(FALSE);
	m_nX--;
	DrawBlock(TRUE);
}


void CSjTetris1Dlg::OnBnClickedButtonStart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	InitialGame();
	m_ctrlStartBt.EnableWindow(FALSE);
	m_ctrlStopBt.EnableWindow(TRUE);
	m_ctrlStopBt.SetFocus();
}


void CSjTetris1Dlg::OnBnClickedButtonStop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	m_bStart = FALSE;
	KillTimer(1);
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
}


void CSjTetris1Dlg::OnBnClickedButtonExit()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	OnOK();
}


void CSjTetris1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	BlockDown();
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CSjTetris1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	if (pMsg->message == WM_KEYDOWN && pMsg->wParam == VK_ESCAPE)
		return TRUE;
	if (pMsg->message == WM_KEYDOWN && m_bStart)
	{
		switch (pMsg->wParam)
		{
		case VK_LEFT:
			MoveLeft();
			return TRUE;
		case VK_RIGHT:
			MoveRight();
			return TRUE;
		case VK_DOWN:
			MoveDown();
			return TRUE;
		case VK_UP:
			RolateBlock(FALSE);
			return TRUE;
		case VK_SPACE:
		case VK_RETURN:
			MoveDown();
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}

void CSjTetris1Dlg::NextBlock(bool bFlag)
{
	// TODO: 여기에 구현 코드 추가.
	int i, x = 50, y = 10;
	if (m_nNextPattern == 0)
		x = 65;
	else if (m_nNextPattern == 1)
		x = 65, y = 0;

	if (bFlag)
	{
		for (i = 0; i < 4; i++)
		{
			m_pDC->BitBlt(m_nextRect.left + x + (nextPattern[m_nNextPattern][i].x) * BLOCK_SIZE,
				m_nextRect.top + y + (nextPattern[m_nNextPattern][i].y) * BLOCK_SIZE,
				BLOCK_SIZE, BLOCK_SIZE, &m_BlockDC, m_nNextPattern * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
		}
	}
	else
	{
		m_pDC->Rectangle(m_nextRect);
	}
}


void CSjTetris1Dlg::DrawScr2()
{
	// TODO: 여기에 구현 코드 추가.
	CDC* pDC = GetDC();
	int x = 0, y = 0;
	for (int i = 1; i < 6; i++)
	{
		if (i < 3)
		{
			x = (i - 1) * (BLOCK_SIZE * COL_CNT / 2 + 14);
			y = 0;
		}
		else
		{
			x = (i - 3) * (BLOCK_SIZE * COL_CNT / 2 + 14) - 175;
			y = BLOCK_SIZE * ROW_CNT / 2 + 54;
		}
		pDC->Rectangle(m_mainRect2.left + x, m_mainRect2.top + y, m_mainRect2.right + x, m_mainRect2.bottom + y);
	}
	DrawScr3();
	/*for (int i = 0; i < 5; i++)
	{
		if (i < 2)
		{
			pDC->Rectangle((i + 2) * BLOCK_SIZE * COL_CNT / 2 + START_X + 185 + (i * 14), START_Y, (i + 3) * BLOCK_SIZE * COL_CNT / 2 + START_X + 189 + (i * 14), BLOCK_SIZE * ROW_CNT / 2 + 14);
		}

		else
		{
			pDC->Rectangle(i * BLOCK_SIZE * COL_CNT / 2 + START_X + 10 + (i - 2) * 14, BLOCK_SIZE * ROW_CNT / 2 + START_Y + 54, (i + 1) * BLOCK_SIZE * COL_CNT / 2 + START_X + 14 + (i - 2) * 14, BLOCK_SIZE * ROW_CNT + START_Y + 58);
		}
	}*/

	/*int row, col;
	for (int i = 1; i < 6; i++)
	{
		for (row = 0; row < ROW_CNT; row++)
		{
			for (col = 0; col < COL_CNT; col++)
			{
				if (m_Table[i][row][col] == -1)
				{
					m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect3.left + 2 + col * BLOCK_SIZE / 2, m_mainRect3.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect4.left + 2 + col * BLOCK_SIZE / 2, m_mainRect4.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect5.left + 2 + col * BLOCK_SIZE / 2, m_mainRect5.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect6.left + 2 + col * BLOCK_SIZE / 2, m_mainRect6.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				}
				else
				{
					m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[1][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect3.left + 2 + col * BLOCK_SIZE / 2, m_mainRect3.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[2][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect4.left + 2 + col * BLOCK_SIZE / 2, m_mainRect4.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[3][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect5.left + 2 + col * BLOCK_SIZE / 2, m_mainRect5.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[4][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					m_pDC->StretchBlt(m_mainRect6.left + 2 + col * BLOCK_SIZE / 2, m_mainRect6.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[5][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				}
			}
		}
	}*/
	/*for (row = 0; row < ROW_CNT; row++)
	{
		for (col = 0; col < COL_CNT; col++)
		{
			if (m_Table2[row][col] == -1)
			{
				m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
					col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect3.left + 2 + col * BLOCK_SIZE / 2, m_mainRect3.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
					col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect4.left + 2 + col * BLOCK_SIZE / 2, m_mainRect4.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
					col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect5.left + 2 + col * BLOCK_SIZE / 2, m_mainRect5.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
					col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect6.left + 2 + col * BLOCK_SIZE / 2, m_mainRect6.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
					col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
			}
			else
			{
				m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
					m_Table2[row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect3.left + 2 + col * BLOCK_SIZE / 2, m_mainRect3.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
					m_Table2[row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect4.left + 2 + col * BLOCK_SIZE / 2, m_mainRect4.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
					m_Table2[row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect5.left + 2 + col * BLOCK_SIZE / 2, m_mainRect5.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
					m_Table2[row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				m_pDC->StretchBlt(m_mainRect6.left + 2 + col * BLOCK_SIZE / 2, m_mainRect6.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
					m_Table2[row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
			}
		}
	}*/
}

void CSjTetris1Dlg::DrawScr3()
{
	// TODO: 여기에 구현 코드 추가.
	int x = 0, y = 0;
	int row, col;
	m_pDC->Rectangle(m_mainRect2);
	for (int i = 1; i < 6; i++)
	{
		if (i < 3)
		{
			x = (i - 1) * (BLOCK_SIZE * COL_CNT / 2 + 14);
			y = 0;
		}
		else
		{
			x = (i - 3) * (BLOCK_SIZE * COL_CNT / 2 + 14) - 175;
			y = BLOCK_SIZE * ROW_CNT / 2 + 54;
		}

		for (row = 0; row < ROW_CNT; row++)
		{
			for (col = 0; col < COL_CNT; col++)
			{
				if (m_Table[i][row][col] == -1)
				{
					m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + x, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + y,
						BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
						col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
				}
				else
				{
					m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + x, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + y, 
						BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
						m_Table[i][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);

				}
			}
		}
	}
	/*for (int i = 1; i < 6; i++)
	{
		if (i < 3)
		{
			for (row = 0; row < ROW_CNT; row++)
			{
				for (col = 0; col < COL_CNT; col++)
				{
					if (m_Table[i][row][col] == -1)
					{
						m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + (i - 1) * (BLOCK_SIZE * COL_CNT / 2 + 14), m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, 
							BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
							col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					}
					else
					{
						m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + (i - 1) * (BLOCK_SIZE * COL_CNT / 2 + 14), m_mainRect2.top + 2 + row * BLOCK_SIZE / 2, BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
							m_Table[i][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);

					}
				}
			}
		}
		else
		{
			for (row = 0; row < ROW_CNT; row++)
			{
				for (col = 0; col < COL_CNT; col++)
				{
					if (m_Table[i][row][col] == -1)
					{
						m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 - 175 + (i - 3) * (BLOCK_SIZE * COL_CNT / 2 + 14), m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + BLOCK_SIZE * ROW_CNT / 2 + 54,
							BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
							col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
					}
					else
					{
						m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 - 175 + (i - 3) * (BLOCK_SIZE * COL_CNT / 2 + 14), m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + BLOCK_SIZE * ROW_CNT / 2 + 54,
							BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
							m_Table[i][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);

					}
				}
			}
		}
	}*/
}
