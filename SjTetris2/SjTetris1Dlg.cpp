
// SjTetris1Dlg.cpp : ���� ����
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


// CSjTetris1Dlg ��ȭ ����



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


// CSjTetris1Dlg �޽��� ó����

BOOL CSjTetris1Dlg::OnInitDialog()
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
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSjTetris1Dlg::OnPaint()
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
		DrawScr();
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
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
		MessageBox(_T("����"));
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	InitialGame();
	m_ctrlStartBt.EnableWindow(FALSE);
	m_ctrlStopBt.EnableWindow(TRUE);
	m_ctrlStopBt.SetFocus();
}


void CSjTetris1Dlg::OnBnClickedButtonStop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bStart = FALSE;
	KillTimer(1);
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
}


void CSjTetris1Dlg::OnBnClickedButtonExit()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}


void CSjTetris1Dlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	BlockDown();
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CSjTetris1Dlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
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
	// TODO: ���⿡ ���� �ڵ� �߰�.
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
