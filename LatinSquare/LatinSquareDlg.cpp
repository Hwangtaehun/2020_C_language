
// LatinSquareDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "LatinSquare.h"
#include "LatinSquareDlg.h"
#include "afxdialogex.h"
#include "HelpDlg.h"

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


// CLatinSquareDlg ��ȭ ����



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


// CLatinSquareDlg �޽��� ó����

BOOL CLatinSquareDlg::OnInitDialog()
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
		MessageBox(_T("���� File�� ������!!"));
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
	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
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

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CLatinSquareDlg::OnPaint()
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
		AllViews();
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CLatinSquareDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CLatinSquareDlg::OnClickedButtonExam()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
			MessageBox(_T("���� ���� ����"));
			return;
		}
		if (fgets(buf2, 90, inf) == NULL)
		{
			MessageBox(_T("���� ���� ����"));
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
		MessageBox(_T("�����մϴ�!!"));
		KillTimer(1);
	}
	else
	{
		str.Format(_T("%d �� Ʋ�Ƚ��ϴ�."), nCnt);
		MessageBox(str);
	}
}


void CLatinSquareDlg::OnClickedButtonHelp()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CHelpDlg dlg;
	dlg.m_strHelp = _T("������ Ǫ�� ���\r\n������� ���� ������ ������ ���� 9���� �簢������ �̷���� �ֽ��ϴ�. \r\n�� �簢�� �ȿ��� 1���� 9������ ���� �������� ���� �մϴ�.�������� ���� ���ٿ��� 1���� 9������ ���� �ϳ��� �����ϸ�, \r\n���� ���ٿ��� 1���� 9������ ���� �������� �ϳ��� ���� �մϴ�.");
	dlg.DoModal();
}


void CLatinSquareDlg::OnClickedButtonHint()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_nHintCnt == 0)
	{
		MessageBox(_T("��Ʈ�� �̹� ���� ����Ͽ����ϴ�."));
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	if (m_cTable[0][0] == 0)
	{
		MessageBox(_T("������ �����!!"));
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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	KillTimer(1);
	m_bGame = false;
	InitGame();
}


void CLatinSquareDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	m_Point = point;
	CDialogEx::OnMouseMove(nFlags, point);
}


void CLatinSquareDlg::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	UpdateData(FALSE);
	m_Time++;
	m_strTime.Format(_T("%2d �� %2d��"), m_Time / 60, m_Time % 60);
	UpdateData(FALSE);
	CDialogEx::OnTimer(nIDEvent);
}


BOOL CLatinSquareDlg::PreTranslateMessage(MSG* pMsg)
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
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
