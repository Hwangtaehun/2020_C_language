
// SjPuzzleDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "SjPuzzle.h"
#include "SjPuzzleDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CSjPuzzleDlg ��ȭ ����



CSjPuzzleDlg::CSjPuzzleDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(CSjPuzzleDlg::IDD, pParent)
	, m_colCnt(5)
	, m_rowCnt(5)
	, m_moveCnt(0)
	, m_nTime(0)
	, m_strCorect(_T(""))
	, m_bNumber(FALSE)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nXSize = 0;
	m_nYSize = 0;
	m_bGameClear = FALSE;
	m_bGameStart = FALSE;
	m_bHint = FALSE;
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
	ON_WM_LBUTTONDOWN()
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CHECK_PNUMBER, &CSjPuzzleDlg::OnClickedShowNumber)
	ON_BN_CLICKED(IDC_BT_EXIT, &CSjPuzzleDlg::OnClickedEndButton)
END_MESSAGE_MAP()


// CSjPuzzleDlg �޽��� ó����

BOOL CSjPuzzleDlg::OnInitDialog()
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
	MoveWindow(100, 100, WINDOW_XSIZE, WINDOW_YSIZE);
	m_pDC = GetDC();
	m_mainDC.CreateCompatibleDC(m_pDC);
	m_hintDC.CreateCompatibleDC(m_pDC);
	m_bitMain.LoadBitmap(IDB_BITMAIN);
	m_bitHint.LoadBitmap(IDB_BITHINT);

	m_mainDC.SelectObject(&m_bitMain);
	m_hintDC.SelectObject(&m_bitHint);

	InitialData();
	m_ctrlStartBt.EnableWindow(!m_bGameStart);
	m_ctrlStopBt.EnableWindow(m_bGameStart);
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CSjPuzzleDlg::OnPaint()
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
		if (m_bGameClear)
		{
			DisplayOriginal();
		}
		else
		{
			DrawRectAll();
			DisplayAll();
			CorrectCount();
		}
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CSjPuzzleDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSjPuzzleDlg::OnClickedStartButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Invalidate();
	InitialData();
	DrawRectAll();
	DisplayAll();
	MixedPicture();
	CorrectCount();
	m_bGameClear = FALSE;
	m_bGameStart = TRUE;
	m_ctrlStartBt.EnableWindow(!m_bGameStart);
	m_ctrlStopBt.EnableWindow(m_bGameStart);
	SetTimer(0, 1000, NULL);
}


void CSjPuzzleDlg::OnClickedStopButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_bGameStart = FALSE;
	m_ctrlStartBt.EnableWindow(!m_bGameStart);
	m_ctrlStopBt.EnableWindow(m_bGameStart);
	KillTimer(0);
}


void CSjPuzzleDlg::OnClickedEndButton()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	OnOK();
}



void CSjPuzzleDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	int x, y, ex, ey;
	CString str;
	if (!m_bGameStart)
		return;
	if (m_mainRect.PtInRect(point))
	{
		ex = x = (point.x - START_X) / (m_nXSize + 2);
		ey = y = (point.y - START_Y) / (m_nYSize + 2);
		if (EmptyPosition(ex, ey))
		{
			MovePicture(x, y, ex, ey, 100);
			m_moveCnt++;

			if (CorrectCount())
			{
				MessageBox(_T("����"));
				ClearGame();
			}
		}
	}
	if (m_hintRect.PtInRect(point))
	{
		SetTimer(1, 5000, NULL);
		m_bHint = TRUE;
		PreView();
	}

	CDialogEx::OnLButtonDown(nFlags, point);
}


void CSjPuzzleDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	if (nIDEvent == 1)
	{
		KillTimer(1);
		m_bHint = FALSE;
		PreView();
		return;
	}
	m_nTime++;
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
	CDialogEx::OnTimer(nIDEvent);
}


void CSjPuzzleDlg::OnClickedShowNumber()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	DrawRectAll();
	DisplayAll();
}


void CSjPuzzleDlg::InitialData()
{
	int x, y, cnt = 0;
	UpdateData(TRUE);
	if (m_colCnt < 3 || m_colCnt > 7)
		m_colCnt = 5;
	if (m_rowCnt < 3 || m_rowCnt > 7)
		m_rowCnt = 5;
	m_nXSize = PIC_SIZE / m_colCnt;
	m_nYSize = PIC_SIZE / m_rowCnt;
	m_mainRect.left = START_X - 1;
	m_mainRect.top = START_Y - 1;
	m_mainRect.right = START_X + m_colCnt * (m_nXSize + 2) + 1;
	m_mainRect.bottom = START_Y + m_rowCnt * (m_nYSize + 2) + 1;
	m_hintRect.left = m_mainRect.right + 20;
	m_hintRect.top = START_Y - 1;
	m_hintRect.right = m_hintRect.left + HINT_SIZE;
	m_hintRect.bottom = START_Y + HINT_SIZE;
	m_strCorect = "";
	m_moveCnt = 0;
	m_nTime = 0;
	for (y = 0; y < m_rowCnt; y++)
	{
		for (x = 0; x < m_colCnt; x++)
		{
			m_aMap[x][y] = cnt++;
		}
	}
	m_aMap[m_colCnt - 1][m_rowCnt - 1] = -1;
}


void CSjPuzzleDlg::DrawRectAll()
{
	int x, y;
	m_pDC->Rectangle(m_mainRect);
	m_pDC->Rectangle(m_hintRect);
	for (x = 0; x < m_colCnt; x++)
	{
		for (y = 0; y < m_rowCnt; y++)
		{
			DrawRect(x, y);
		}
	}
	PreView();
}


void CSjPuzzleDlg::DrawRect(int nX, int nY)
{
	m_pDC->Rectangle(START_X + nX * (m_nXSize + 2), START_Y + nY * (m_nYSize + 2), START_X + (nX + 1) * (m_nXSize + 2), START_Y + (nY + 1) * (m_nYSize + 2));
}


void CSjPuzzleDlg::DisplayAll()
{
	int x, y;
	for (x = 0; x < m_colCnt; x++)
	{
		for (y = 0; y < m_rowCnt; y++)
		{
			DrawPicture(x, y, m_aMap[x][y]);
		}
	}
}


void CSjPuzzleDlg::DrawPicture(int nX, int nY, int nPictureNo)
{
	int x, y;
	x = (int)(nPictureNo % m_colCnt);
	y = (int)(nPictureNo / m_colCnt);

	m_pDC->BitBlt(START_X + 1 + (nX * (m_nXSize + 2)), START_Y + 1 + (nY * (m_nYSize + 2)), m_nXSize, m_nYSize, &m_mainDC, (x * m_nXSize), (y * m_nYSize), SRCCOPY);
	if (m_bNumber)
		DisplayNumber();
}


BOOL CSjPuzzleDlg::CorrectCount()
{
	int x, y, cnt = 0, correct = 0;
	for (y = 0; y < m_rowCnt; y++)
	{
		for (x = 0; x < m_colCnt; x++)
		{
			if (m_aMap[x][y] == cnt)
				correct++;
			cnt++;
		}
	}
	if (m_aMap[m_colCnt - 1][m_rowCnt - 1] == -1)
		correct++;

	m_strCorect.Format(_T(" %d / %d "), correct, m_colCnt * m_rowCnt);
	UpdateData(FALSE);
	if (correct == m_colCnt * m_rowCnt)
		return TRUE;
	else
		return FALSE;
}


void CSjPuzzleDlg::DisplayNumber()
{
	int x, y;
	CString str;
	for (x = 0; x < m_colCnt; x++)
	{
		for (y = 0; y < m_rowCnt; y++)
		{
			str.Format(_T("%2d"), m_aMap[x][y]);
			m_pDC->TextOut(START_X + x * (m_nXSize + 2) + 2, START_Y + y * (m_nYSize + 2) + 2, str);
		}
	}
}


BOOL CSjPuzzleDlg::EmptyPosition(int& nX, int& nY)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i;
	for (i = 0; i < m_colCnt; i++)
	{
		if (m_aMap[i][nY] == -1)
		{
			nX = i;
			return TRUE;
		}
	}
	for (i = 0; i < m_rowCnt; i++)
	{
		if (m_aMap[nX][i] == -1)
		{
			nY = i;
			return TRUE;
		}
	}
	return FALSE;
}


void CSjPuzzleDlg::MovePicture(int nX, int nY, int eX, int eY, int nTime)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i;
	if (nX > eX)
	{
		for (i = eX; i < nX; i++)
		{
			m_aMap[i][nY] = m_aMap[i + 1][nY];
			DrawPicture(i, nY, m_aMap[i][nY]);
			DrawRect(i + 1, nY);
			Sleep(nTime);
		}
	}
	else if (nX < eX)
	{
		for (i = eX; i > nX; i--)
		{
			m_aMap[i][nY] = m_aMap[i - 1][nY];
			DrawPicture(i, nY, m_aMap[i][nY]);
			DrawRect(i - 1, nY);
			Sleep(nTime);
		}
	}
	else if (nY > eY)
	{
		for (i = eY; i < nY; i++)
		{
			m_aMap[nX][i] = m_aMap[nX][i + 1];
			DrawPicture(nX, i, m_aMap[nX][i]);
			DrawRect(nX, i + 1);
			Sleep(nTime);
		}
	}
	else if (nY < eY)
	{
		for (i = eY; i > nY; i--)
		{
			m_aMap[nX][i] = m_aMap[nX][i - 1];
			DrawPicture(nX, i, m_aMap[nX][i]);
			DrawRect(nX, i - 1);
			Sleep(nTime);
		}
	}
	m_aMap[nX][nY] = -1;
}


void CSjPuzzleDlg::DisplayOriginal()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_pDC->BitBlt(START_X + m_colCnt, START_Y + m_rowCnt, PIC_SIZE, PIC_SIZE, &m_mainDC, 0, 0, SRCCOPY);
}


void CSjPuzzleDlg::PreView()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	if (m_bHint)
		m_pDC->StretchBlt(m_hintRect.left, m_hintRect.top, HINT_SIZE, HINT_SIZE, &m_mainDC, 0, 0, PIC_SIZE, PIC_SIZE, SRCCOPY);
	else
		m_pDC->BitBlt(m_hintRect.left, m_hintRect.top, HINT_SIZE, HINT_SIZE, &m_hintDC, 0, 0, SRCCOPY);
}


void CSjPuzzleDlg::ClearGame()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	m_bGameStart = FALSE;
	m_ctrlStartBt.EnableWindow(!m_bGameStart);
	m_ctrlStopBt.EnableWindow(m_bGameStart);
	KillTimer(0);
	m_bGameClear = TRUE;
	DisplayOriginal();
}


void CSjPuzzleDlg::MixedPicture()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int x, y, ex, ey;
	srand((unsigned)time(NULL));
	for (int i = 0; i < m_colCnt * m_rowCnt * 10; i++)
	{
		ex = x = rand() % m_colCnt;
		ey = y = rand() % m_rowCnt;
		if (EmptyPosition(ex, ey))
		{
			MovePicture(x, y, ex, ey, 1);
		}
	}
}
