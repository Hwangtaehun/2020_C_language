
// LatinSquareDlg.cpp : 구현 파일
//

#include "stdafx.h"
#include "LatinSquare.h"
#include "LatinSquareDlg.h"
#include "afxdialogex.h"
#include "HelpDlg.h"

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


// CLatinSquareDlg 대화 상자



CLatinSquareDlg::CLatinSquareDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CLatinSquareDlg::IDD, pParent)
	, m_nExamNo(1)
	, m_nHintCnt(5)
	, m_strTime(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLatinSquareDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EXAM_NO, m_nExamNo);
	DDX_Text(pDX, IDC_HINT_CNT, m_nHintCnt);
	DDX_Text(pDX, IDC_TIME, m_strTime);
	DDX_Control(pDX, IDC_BT_GAMESTART, m_ctrlStartBt);
	DDX_Control(pDX, IDC_BT_GAMESTOP, m_ctrlStopBt);
	DDX_Control(pDX, IDC_BT_EXAM, m_ctrlExamBt);
	DDX_Control(pDX, IDC_BT_HINT, m_ctrlHintBt);
	DDX_Control(pDX, IDC_BT_CHECK, m_ctrlCheckBt);
	DDX_Control(pDX, IDC_SPIN_NUMBER, m_ctrlSpin);
	DDX_Control(pDX, IDC_BT_EXAMST, m_ctrlSaveBt);
}

BEGIN_MESSAGE_MAP(CLatinSquareDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BT_EXAM, &CLatinSquareDlg::OnClickedButtonExam)
	ON_BN_CLICKED(IDC_BT_CHECK, &CLatinSquareDlg::OnClickedButtonCheck)
	ON_BN_CLICKED(IDC_BT_HELP, &CLatinSquareDlg::OnClickedButtonHelp)
	ON_BN_CLICKED(IDC_BT_HINT, &CLatinSquareDlg::OnClickedButtonHint)
	ON_BN_CLICKED(IDC_BT_GAMESTART, &CLatinSquareDlg::OnClickedButtonGamestart)
	ON_BN_CLICKED(IDC_BT_GAMESTOP, &CLatinSquareDlg::OnClickedButtonGamestop)
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_TIMER()
END_MESSAGE_MAP()


// CLatinSquareDlg 메시지 처리기

BOOL CLatinSquareDlg::OnInitDialog()
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
	m_NumberDC.CreateCompatibleDC(m_pDC);
	m_bmNumber.LoadBitmap(IDB_NUMBER);
	m_NumberDC.SelectObject(&m_bmNumber);
	m_NumRect.left = START_X;
	m_NumRect.top = START_Y;
	m_NumRect.right = m_NumRect.left + DISP_SIZE * NUM_CNT + 12;
	m_NumRect.bottom = m_NumRect.top + DISP_SIZE * NUM_CNT + 12;
	m_bGame = false;
	InitGame();
	FILE* inf;
	if ((fopen_s(&inf, "sudoku1.txt", "rt")) != NULL)
	{
		MessageBox(_T("문제 File이 없네유!!"));
	}
	else
	{
		fseek(inf, 0L, SEEK_END);
		m_munCnt = ftell(inf) / sizeof(m_aTable) / 2;
		fclose(inf);
	}
	m_nExamNo = m_munCnt;
	UpdateData(FALSE);
	m_ctrlSpin.SetRange(1, m_munCnt);
	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CLatinSquareDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLatinSquareDlg::OnPaint()
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
		AllViews();
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CLatinSquareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLatinSquareDlg::OnClickedButtonExam()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	char buf1[90], buf2[90];
	FILE* inf;
	int i;
	UpdateData(TRUE);
	if ((fopen_s(&inf, "sudoku1.txt", "rt")) != NULL)
	{
		MessageBox(_T("Data File Open Error"));
		return;
	}
	for (i = 0; i < m_nExamNo; i++)
	{
		if (fgets(buf1, 90, inf) == NULL)
		{
			MessageBox(_T("문제 법위 오류"));
			return;
		}
		if (fgets(buf2, 90, inf) == NULL)
		{
			MessageBox(_T("문제 법위 오류"));
			return;
		}
	}
	for (i = 0; i < 81; i++)
	{
		m_aTable[i / 9][i % 9] = buf1[i] - '0';
		m_cTable[i / 9][i % 9] = buf2[i] - '0';
	}
	fclose(inf);
	AllViews();
	m_ctrlCheckBt.EnableWindow(m_bGame);
	m_ctrlHintBt.EnableWindow(m_bGame);
	m_ctrlStartBt.EnableWindow(!m_bGame);
	m_ctrlStopBt.EnableWindow(m_bGame);
	m_ctrlExamBt.EnableWindow(!m_bGame);
	m_ctrlSaveBt.EnableWindow(false);
	SetFocus();
}


void CLatinSquareDlg::OnClickedButtonCheck()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	int i, j, nCnt = 0;
	CString str;
	AllViews();
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
			if (m_aTable[i][j] == 0 && m_bTable[i][j] != m_cTable[i][j])
			{
				DrawX(j, i);
				nCnt++;
			}
		}
	}
	if (nCnt == 0)
	{
		MessageBox(_T("축하합니다!!"));
		KillTimer(1);
	}
	else
	{
		str.Format(_T("%d 개 틀렸습니다."), nCnt);
		MessageBox(str);
	}
}


void CLatinSquareDlg::OnClickedButtonHelp()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CHelpDlg dlg;
	dlg.m_strHelp = _T("스도쿠를 푸는 방법\r\n스도쿠는 굵은 선으로 나눠진 작은 9개의 사각형으로 이루어져 있습니다. \r\n이 사각형 안에는 1부터 9까지의 수가 빠짐없이 들어가야 합니다.스토쿠의 가로 한줄에는 1부터 9까지의 수가 하나씩 들어가야하며, \r\n세로 한줄에도 1부터 9까지의 수가 빠짐없이 하나씩 들어가야 합니다.");
	dlg.DoModal();
}


void CLatinSquareDlg::OnClickedButtonHint()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_nHintCnt == 0)
	{
		MessageBox(_T("힌트를 이미 전부 사용하였습니다."));
	}
	else
	{
		m_bTable[m_nY][m_nX] = m_cTable[m_nY][m_nX];
		AllViews();
		DrawBox(m_nX, m_nY);
		m_nHintCnt--;
		UpdateData(FALSE);
	}
}


void CLatinSquareDlg::OnClickedButtonGamestart()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	if (m_cTable[0][0] == 0)
	{
		MessageBox(_T("문제가 없어요!!"));
		return;
	}
	m_bGame = true;
	SetTimer(1, 1000, NULL);
	InitGame();
	AllViews();
	DrawBox(m_nX, m_nY);
	SetFocus();
}


void CLatinSquareDlg::OnClickedButtonGamestop()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	KillTimer(1);
	m_bGame = false;
	InitGame();
}


void CLatinSquareDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (m_NumRect.PtInRect(point))
	{
		int x, y, n = 0;
		if (point.x <= START_X + DISP_SIZE * 3)
			n = 0;
		else if (point.x >= START_X + DISP_SIZE * 6)
			n = 12;
		else
			n = 6;
		x = (point.x - START_X - n + 2) / DISP_SIZE;
		if (point.y <= START_Y + DISP_SIZE * 3)
			n = 0;
		else if (point.y >= START_Y + DISP_SIZE * 6)
			n = 12;
		else
			n = 6;
		y = (point.y - START_Y - n + 2) / DISP_SIZE;
		DrawBox(x, y);
	}
	CDialogEx::OnLButtonDown(nFlags, point);
}


void CLatinSquareDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	m_Point = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CLatinSquareDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	UpdateData(FALSE);
	m_Time++;
	m_strTime.Format(_T("%2d 분 %2d초"), m_Time / 60, m_Time % 60);
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CLatinSquareDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	int i, x, y;
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam == VK_RETURN || pMsg->wParam == VK_ESCAPE))
	{
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN && (pMsg->wParam >= '1' && pMsg->wParam <= '9'))
	{
		if (m_bGame)
		{
			m_bTable[m_nY][m_nX] = pMsg->wParam - '0';
			i = IsNumber(pMsg->wParam - '0');
			ViewPic(m_nX, m_nY);
			DrawBox(m_nX, m_nY);
			if (i != 0)
				DrawX(m_nX, m_nY);
		}
		return TRUE;
	}
	if (pMsg->message == WM_KEYDOWN)
	{
		x = m_nX;
		y = m_nY;
		switch (pMsg->wParam)
		{
		case VK_LEFT:
			for (i = 0; i < NUM_CNT; i++)
			{
				if (x == 0)
					x = NUM_CNT;
				x--;
				if (m_aTable[y][x] == 0)
					break;
			}
			DrawBox(x, y);
			return TRUE;
		case VK_RIGHT:
			for (i = 0; i < NUM_CNT; i++)
			{
				if (x == NUM_CNT - 1)
					x = -1;
				x++;
				if (m_aTable[y][x] == 0)
					break;
			}
			DrawBox(x, y);
			return TRUE;
		case VK_DOWN:
			for (i = 0; i < NUM_CNT; i++)
			{
				if (y == NUM_CNT - 1)
					y = -1;
				y++;
				if (m_aTable[y][x] == 0)
					break;
			}
			DrawBox(x, y);
			return TRUE;
		case VK_UP:
			for (i = 0; i < NUM_CNT; i++)
			{
				if (y == 0)
					y = NUM_CNT;
				y--;
				if (m_aTable[y][x] == 0)
					break;
			}
			DrawBox(x, y);
			return TRUE;
		}
	}
	return CDialogEx::PreTranslateMessage(pMsg);
}


void CLatinSquareDlg::InitGame()
{
	m_nExamNo = 1;
	m_nHintCnt = 5;
	m_Time = 0;
	memset((void *)m_bTable, 0, sizeof(m_bTable));
	m_ctrlCheckBt.EnableWindow(m_bGame);
	m_ctrlHintBt.EnableWindow(m_bGame);
	m_ctrlStopBt.EnableWindow(m_bGame);
	m_ctrlExamBt.EnableWindow(!m_bGame);
	m_ctrlStartBt.EnableWindow(!m_bGame);
	UpdateData(FALSE);
}


void CLatinSquareDlg::AllViews()
{
	int x = 0, y;
	for (x = 0; x < NUM_CNT; x++)
	{
		for (y = 0; y < NUM_CNT; y++)
		{
			ViewPic(x, y);
		}
	}
	DrawLine();
}


void CLatinSquareDlg::DrawLine()
{
	CPen pen, *pPen;
	int i, j, x, y;
	pen.CreatePen(PS_SOLID, 2, RGB(0, 0, 255));
	pPen = m_pDC->SelectObject(&pen);
	CBrush br = NULL;
	m_pDC->SelectStockObject(NULL_BRUSH);
	for (i = 0; i < NUM_CNT; i++)
	{
		for (j = 0; j < NUM_CNT; j++)
		{
			x = START_X + i * DISP_SIZE + (i / 3) * 6;
			y = START_Y + j * DISP_SIZE + (j / 3) * 6;
			m_pDC->Rectangle(x - 2, y - 2, x + DISP_SIZE - 2, y + DISP_SIZE - 2);
		}
	}
	m_pDC->SelectObject(pPen);
}


void CLatinSquareDlg::ViewPic(int x, int y)
{
	int style, num;
	if (m_aTable[y][x] == 0)
	{
		style = 0;
		num = m_bTable[y][x];
	}
	else
	{
		style = BMP_SIZE;
		num = m_aTable[y][x];
	}
	m_pDC->BitBlt(START_X + x * DISP_SIZE + (x / 3) * 6, START_Y + y * DISP_SIZE + (y / 3) * 6, BMP_SIZE, BMP_SIZE, &m_NumberDC, style, (num * BMP_SIZE), SRCCOPY);
}


void CLatinSquareDlg::DrawBox(int x, int y)
{
	if (m_aTable[y][x] != 0)
		return;
	int sx, sy;
	CPen pen, *pPen;
	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	pPen = (CPen*)m_pDC->SelectObject(&pen);
	ViewPic(m_nX, m_nY);
	sx = START_X + x * DISP_SIZE + (x / 3) * 6 + 1;
	sy = START_Y + y * DISP_SIZE + (y / 3) * 6 + 1;
	m_pDC->Rectangle(sx, sy, sx + DISP_SIZE - 6, sy + DISP_SIZE - 6);
	m_nX = x;
	m_nY = y;
	m_pDC->SelectObject(pPen);
}


int CLatinSquareDlg::IsNumber(int n)
{
	int i, j, cnt = 0;
	AllViews();
	for (i = m_nX / 3 * 3; i < m_nX / 3 * 3 + 3; i++)
	{
		for (j = m_nY / 3 * 3; j < m_nY / 3 * 3 + 3; j++)
		{
			if ((m_aTable[j][i] == n || m_bTable[j][i] == n))
			{
				DrawX(i, j);
			}
			if ((m_aTable[j][i] == n || m_bTable[j][i] == n) && m_nX != i && m_nY != j)
				cnt++;
		}
	}
	for (i = 0; i < NUM_CNT; i++)
	{
		if ((m_aTable[m_nY][i] == n || m_bTable[m_nY][i] == n) && m_nX != 1)
		{
			DrawX(i, m_nY);
			cnt++;
		}
		if ((m_aTable[i][m_nX] == n || m_bTable[i][m_nX] == n) && m_nY != 1)
		{
			DrawX(m_nX, i);
			cnt++;
		}
	}
	return cnt;
}


bool CLatinSquareDlg::IsDuplicate(int x, int y, int num)
{
	return false;
}


void CLatinSquareDlg::DrawX(int x, int y)
{
	int sx, sy;
	CPen pen, *pPen;
	pen.CreatePen(PS_SOLID, 2, RGB(255, 0, 0));
	pPen = (CPen*)m_pDC->SelectObject(&pen);
	sx = START_X + x * DISP_SIZE + (x / 3) * 6;
	sy = START_Y + y * DISP_SIZE + (y / 3) * 6;
	m_pDC->MoveTo(sx, sy);
	m_pDC->LineTo(sx + DISP_SIZE - 4, sy + DISP_SIZE - 4);
	m_pDC->MoveTo(sx + DISP_SIZE - 4, sy);
	m_pDC->LineTo(sx, sy + DISP_SIZE - 4);
}


void CLatinSquareDlg::WriteFile()
{
	CFile file;
	file.Open(_T("sudoku1.txt"), CFile::modeCreate | CFile::modeWrite);


}
