
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

struct GUSET_DATA
{
	CString strName;
	int nScore;
	//void *pClient;
	CSjClientSocket* pClient;
	char cFlag;
}m_Guest[USER_CNT];

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
	, m_nMyNo(0)
	, m_nConnectCnt(0)
	, m_strName(_T(""))
	, m_nPortNo(1234)
	, m_strSendData(_T(""))
	, m_strIpAddress(_T(""))
	, m_nGameMode(2)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
	m_nX = COL_CNT / 2;
	m_nY = 0;
	m_nPattern = 0;
	m_nRot = 0;
	//m_bStart = FALSE;
	m_nBitType = 1;
	m_nNextPattern = 0;
	m_nState = STATE_INIT;
	m_nScore = 0;
	m_nStage = 0;
	m_nTime = 0;

	m_mainRect.left = START_X;
	m_mainRect.top = START_Y;
	m_mainRect.right = START_X + BLOCK_SIZE * COL_CNT + 4;
	m_mainRect.bottom = START_Y + BLOCK_SIZE * ROW_CNT + 4;

	m_nextRect.left = START_X + BLOCK_SIZE * COL_CNT + 22;
	m_nextRect.top = START_Y + 30;
	m_nextRect.right = m_nextRect.left + 130;
	m_nextRect.bottom = m_nextRect.top + 80;

	/*m_mainRect2.left = m_nextRect.right + 35;
	m_mainRect2.top = START_Y;
	m_mainRect2.right = m_mainRect2.left + BLOCK_SIZE * COL_CNT / 2 + 4;
	m_mainRect2.bottom = START_Y + BLOCK_SIZE * ROW_CNT / 2 + 4;*/
	m_nState = 0;
	m_nMyNo = 0;
	m_nConnectCnt = 0;
	m_nScore = 0;
	m_nStage = 0;
	m_nTime = 0;
}

void CSjTetris1Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON_START, m_ctrlStartBt);
	DDX_Control(pDX, IDC_BUTTON_STOP, m_ctrlStopBt);
	DDX_Control(pDX, IDC_CONNECT_BT, m_ctrlConnectBt);
	DDX_Control(pDX, IDC_DISCONNECT_BT, m_ctrlDisConnectBt);
	//  DDX_Control(pDX, IDC_SEND_BT, m_ctrlSendBt);
	DDX_Text(pDX, IDC_NAME, m_strName);
	DDX_Text(pDX, IDC_PORTNO, m_nPortNo);
	DDX_Text(pDX, IDC_SEND_DATA, m_strSendData);
	DDX_Control(pDX, IDC_SEND_DATA, m_ctrlSendData);
	DDX_Text(pDX, IDC_IP_ADDRESS, m_strIpAddress);
	DDX_Control(pDX, IDC_IP_ADDRESS, m_ctrlIpAddress);
	DDX_Control(pDX, IDC_RADIOSERVER, m_ctrlRadioServer);
	DDX_Control(pDX, IDC_RADIOSINGLE, m_ctrlRadioSingle);
	DDX_Control(pDX, IDC_RADIOCLIENT, m_ctrlRadioClient);
	DDX_Radio(pDX, IDC_RADIOSERVER, m_nGameMode);
}

BEGIN_MESSAGE_MAP(CSjTetris1Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_START, &CSjTetris1Dlg::OnBnClickedButtonStart)
	ON_BN_CLICKED(IDC_BUTTON_STOP, &CSjTetris1Dlg::OnBnClickedButtonStop)
	ON_BN_CLICKED(IDC_BUTTON_EXIT, &CSjTetris1Dlg::OnBnClickedButtonExit)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_CONNECT_BT, &CSjTetris1Dlg::OnClickedConnectBt)
	ON_BN_CLICKED(IDC_DISCONNECT_BT, &CSjTetris1Dlg::OnClickedDisconnectBt)
	ON_CONTROL_RANGE(BN_CLICKED, IDC_RADIOSERVER, IDC_RADIOSINGLE, OnGameMode)
	ON_MESSAGE(UM_ACCEPT, &CSjTetris1Dlg::OnAcceptMsg)
	ON_MESSAGE(UM_RECEIVE, &CSjTetris1Dlg::OnReceiveMsg)
	ON_MESSAGE(UM_SOCKET_CLOSE, &CSjTetris1Dlg::OnCloseMsg)
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
	MoveWindow(100, 100, m_mainRect.right * 2 + 320, m_mainRect.bottom + 140);
	m_pDC = GetDC();
	m_bmBlock.LoadBitmap(IDB_BLOCK);
	m_BlockDC.CreateCompatibleDC(m_pDC);
	m_BlockDC.SelectObject(&m_bmBlock);
	m_bmBack.LoadBitmap(IDB_BACKGROUND);
	m_BackDC.CreateCompatibleDC(m_pDC);
	m_BackDC.SelectObject(&m_bmBack);
	m_bmBack2.LoadBitmap(IDB_STOP);
	m_BackDC2.CreateCompatibleDC(m_pDC);
	m_BackDC2.SelectObject(&m_bmBack2);
	m_bmNumber.LoadBitmap(IDB_NUMBER);
	m_NumberDC.CreateCompatibleDC(m_pDC);
	m_NumberDC.SelectObject(&m_bmNumber);

	char hostName[32];
	struct in_addr myIpAddr;
	HOSTENT* pHostEnt = NULL;
	gethostname(hostName, sizeof(hostName));
	pHostEnt = gethostbyname(hostName);
	myIpAddr.S_un.S_addr = *((u_long*)(pHostEnt->h_addr_list[0]));
	m_strIpAddress = inet_ntoa(myIpAddr);
	UpdateData(FALSE);
	m_ctrlConnectBt.EnableWindow(TRUE);
	m_ctrlDisConnectBt.EnableWindow(FALSE);
	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	//m_ctrlSendBt.EnableWindow(FALSE);

	srand((unsigned)time(NULL));
	memset((void*)m_Table, -1, sizeof(m_Table));
	//memset((void*)m_Table2, -1, sizeof(m_Table2));
	InitGuestData();
	OnGameMode(NULL);
	DisplayMsg(_T("6�ο� NetWork Tetris �Դϴ�."));
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
		DrawScr2();
		DisplayAllGuest();
		DisplayMsg(_T(""));
		NextBlock(FALSE);
		if (m_nState == STATE_GAME_START)
		{
			NextBlock(TRUE);
		}
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
	int i, j, temp, startX, startY;
	m_pDC->Draw3dRect(HOST_X, HOST_Y, HOST_XSIZE + 4, HOST_YSIZE + 3, RGB(128, 128, 128), RGB(255, 255, 255));
	m_pDC->SetTextColor(RGB(0, 0, 255));
	m_pDC->SetBkColor(RGB(190, 190, 190));
	for (i = 0; i < USER_CNT; i++)
	{
		if (i<USER_CNT/2)
		{
			startX = GUEST_X + i * (GUEST_XSIZE + 10) + 4;
			startY = GUEST_Y;
		}
		else
		{
			startX = GUEST_X + ((i - 3) * (GUEST_XSIZE + 10)) + 4;
			startY = GUEST_Y + GUEST_YSIZE + 60;
		}
		m_pDC->Draw3dRect(startX, startY, GUEST_XSIZE + 4, GUEST_YSIZE + 4, RGB(128, 128, 128), RGB(255, 255, 255));
		m_pDC->Draw3dRect(startX, startY + GUEST_YSIZE + 8, GUEST_XSIZE + 4, 46, RGB(128, 128, 128), RGB(255, 255, 255));
		m_pDC->TextOut(startX + 8, startY + GUEST_YSIZE + 10, _T("                  "));
		m_pDC->TextOut(startX + 8, startY + GUEST_YSIZE + 10, m_Guest[i].strName);
		temp = m_Guest[i].nScore;
		for (j = 9; j >= 0; j--)
		{
			if (temp > 0)
			{
				m_pDC->BitBlt(startX + 8 + j * 13, startY + GUEST_YSIZE + 28, 13, 23, &m_NumberDC, 0, (temp % 10) * 23, SRCCOPY);
				temp /= 10;
			}
			else
			{
				m_pDC->BitBlt(startX + 8 + j * 13, startY + GUEST_YSIZE + 28, 13, 23, &m_NumberDC, 0, 11 * 23, SRCCOPY);
				temp /= 10;
			}
		}
	}
	if (m_nState == STATE_GAME_START)
		NextBlock(TRUE);
	else
		NextBlock(FALSE);

	//int row, col;
	//m_pDC->Rectangle(m_mainRect);
	//m_pDC->Rectangle(m_nextRect);
	//for (row = 0; row < ROW_CNT; row++)
	//{
	//	for (col = 0; col < COL_CNT; col++)
	//	{
	//		if (m_Table[0][row][col] == -1)
	//		{
	//			m_pDC->BitBlt(START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, &m_BackDC, col * BLOCK_SIZE, row *BLOCK_SIZE, SRCCOPY);
	//		}
	//		else
	//		{
	//			m_pDC->BitBlt(START_X + 2 + col * BLOCK_SIZE, START_Y + 2 + row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, &m_BlockDC,
	//				m_Table[0][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
	//		}
	//	}
	//}
	//DrawScr2();
	////m_nScore += 10;
	//NextBlock(m_bStart);
}


void CSjTetris1Dlg::InitialGame()
{
	memset((void *)m_Table, -1, sizeof(m_Table));
	DrawScr();
	DrawScr2();
	DisplayAllGuest();
	NextBlock(FALSE);

	m_nPattern = rand() % 7;
	m_nRot = 0;
	m_nY = 1;
	m_nX = COL_CNT / 2;
	//m_bStart = TRUE;
	m_nNextPattern = rand() % 7;

	DrawBlock(TRUE);
	NextBlock(TRUE);
	SetTimer(1, 500, NULL);

	m_ctrlStartBt.EnableWindow(TRUE);
	m_ctrlStopBt.EnableWindow(FALSE);
	m_ctrlRadioServer.EnableWindow(FALSE);
	m_ctrlRadioClient.EnableWindow(FALSE);
	m_ctrlRadioSingle.EnableWindow(FALSE);
	m_ctrlSendData.SetFocus();
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
	m_Guest[0].nScore += rand() % 5 + 1;
	DrawScr();
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
		if (m_Table[0][row][col] != -1)
		{
			return FALSE;
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
				m_Guest[0].nScore += 10;
				DrawScr();
				Sleep(20);
			}
			//UpdateData(TRUE);
			//m_nScore += 10;
			//UpdateData(FALSE);
			DrawScr2();
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
	/*for (int i = 1; i < 6; i++)
	{
		memcpy((void*)m_Table[i], (void*)m_Table[0], COL_CNT * ROW_CNT);
	}
	DrawScr2();*/
	for (int i = 1; i < USER_CNT; i++)
	{
		memcpy((void*)m_Table[i], (void*)m_Table[0], COL_CNT * ROW_CNT);
	}
	DisplayAllGuest();
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
		m_nState = STATE_GAME_DIE;
		DrawScr2();
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
	m_nState = STATE_GAME_START;
}


void CSjTetris1Dlg::OnBnClickedButtonStop()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	m_nState = STATE_INIT;
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
	if (pMsg->message == WM_KEYDOWN && m_nState == STATE_GAME_START)
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
	int row, col;
	CDC* pDC;
	if (m_nState == STATE_GAME_DIE)
		pDC = &m_BackDC2;
	else
		pDC = &m_BackDC;
	
	for (row = 0; row < ROW_CNT; row++)
	{
		for (col = 0; col < COL_CNT; col++)
		{
			if (m_Table[0][row][col] == -1)
			{
				m_pDC->BitBlt(HOST_X + 2 + col * BLOCK_SIZE, HOST_Y + row * BLOCK_SIZE + 2, BLOCK_SIZE, BLOCK_SIZE, pDC, col * BLOCK_SIZE, row * BLOCK_SIZE, SRCCOPY);
			}
			else
			{
				m_pDC->BitBlt(HOST_X + 2 + col * BLOCK_SIZE, HOST_Y + row * BLOCK_SIZE + 2, BLOCK_SIZE, BLOCK_SIZE, &m_BlockDC, m_Table[0][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
			}
		}
	}

	//CDC* pDC = GetDC();
	//int x = 0, y = 0;
	//for (int i = 1; i < 6; i++)
	//{
	//	if (i < 3)
	//	{
	//		x = (i - 1) * (BLOCK_SIZE * COL_CNT / 2 + 14);
	//		y = 0;
	//	}
	//	else
	//	{
	//		x = (i - 3) * (BLOCK_SIZE * COL_CNT / 2 + 14) - 175;
	//		y = BLOCK_SIZE * ROW_CNT / 2 + 54;
	//	}
	//	//pDC->Rectangle(m_mainRect2.left + x, m_mainRect2.top + y, m_mainRect2.right + x, m_mainRect2.bottom + y);
	//	DrawScr3(i, x, y);
	//}

	//int x = BLOCK_SIZE * COL_CNT / 2; // 2 * x = BLOCK_SIZE * ROW_CNT / 2
	//CDC* pDC = GetDC();

	//for (int i = 0; i < 5; i++)
	//{
	//	if (i < 2)
	//	{
	//		pDC->Rectangle((i + 2) * BLOCK_SIZE * COL_CNT / 2 + 195 + (i * 14), 10, (i + 3) * BLOCK_SIZE * COL_CNT / 2 + 199 + (i * 14), BLOCK_SIZE * ROW_CNT / 2 + 14);
	//	}

	//	else
	//	{
	//		pDC->Rectangle(i * x + 20 + (i - 2) * 14, 2 * x + 64, (i + 1) * x + 24 + (i - 2) * 14, 4 * x + 68);
	//	}
	//}
	//DrawScr3();

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

void CSjTetris1Dlg::DrawScr3(void* pt, int nClientNo, bool bFlag)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int row = GUEST_Y, col = GUEST_X, startX, startY;
	char(*GuestTable)[COL_CNT] = (char(*)[COL_CNT])pt;
	CDC* memDC = (bFlag) ? &m_BackDC : &m_BackDC2;
	if (nClientNo < USER_CNT /2)
	{
		startX = GUEST_X + nClientNo * (GUEST_XSIZE + 10) + 6;
		startY = GUEST_Y + 2;
	}
	else
	{
		startX = GUEST_X + ((nClientNo - 3) * (GUEST_XSIZE + 10)) + 6;
		startY = GUEST_Y + GUEST_YSIZE + 60;
	}
	for (row = 0; row < ROW_CNT; row++)
	{
		for (col = 0; col < COL_CNT; col++)
		{
			if (GuestTable[row][col] == -1)
				m_pDC->StretchBlt(startX + col * 14, startY + row * 14, 14, 14, memDC, col * 24, row * 24, 24, 24, SRCCOPY);
			else
				m_pDC->StretchBlt(startX + col * 14, startY + row * 14, 14, 14, &m_BlockDC, GuestTable[row][col] * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, m_nBitType * BLOCK_SIZE, SRCCOPY);
		}
	}

	//int row, col;
	//for (row = 0; row < ROW_CNT; row++)
	//{
	//	for (col = 0; col < COL_CNT; col++)
	//	{
	//		if (m_Table[i][row][col] == -1)
	//		{
	//			//m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + x, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + y,
	//				BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BackDC,
	//				col * BLOCK_SIZE, row * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);
	//		}
	//		else
	//		{
	//			//m_pDC->StretchBlt(m_mainRect2.left + 2 + col * BLOCK_SIZE / 2 + x, m_mainRect2.top + 2 + row * BLOCK_SIZE / 2 + y,
	//				BLOCK_SIZE / 2, BLOCK_SIZE / 2, &m_BlockDC,
	//				m_Table[i][row][col] * BLOCK_SIZE, m_nBitType * BLOCK_SIZE, BLOCK_SIZE, BLOCK_SIZE, SRCCOPY);

	//		}
	//	}
	//}

	/*int row, col;
	m_pDC->Rectangle(m_mainRect2);
	for (int i = 1; i < 6; i++)
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
		}*/
	//}
}


void CSjTetris1Dlg::OnClickedConnectBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

}


void CSjTetris1Dlg::OnClickedDisconnectBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CSjTetris1Dlg::OnClickedSendBt()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


LRESULT CSjTetris1Dlg::OnAcceptMsg(WPARAM wParam, LPARAM IParam)
{
	return LRESULT();
}


LRESULT CSjTetris1Dlg::OnReceiveMsg(WPARAM wParam, LPARAM IParam)
{

	return LRESULT();
}


LRESULT CSjTetris1Dlg::OnCloseMsg(WPARAM wParam, LPARAM IParam)
{
	return LRESULT();
}


void CSjTetris1Dlg::DisplayMsg(CString strMsg)
{
	int i, r = 0, g = 255, b = 0;
	m_pDC->SetBkMode(TRANSPARENT);
	if (!strMsg.IsEmpty())
	{
		for (i = MSG_CNT - 1; i > 0; i--)
		{
			m_arrMsg[i] = m_arrMsg[i - 1];
		}
		m_arrMsg[0] = strMsg;
	}
	for (i = 0; i < 10; i++)
	{
		m_pDC->SetTextColor(RGB(r, g, b));
		g -= 20;
		m_pDC->TextOut(HOST_X + 5, HOST_Y + i * 20, m_arrMsg[i]);
	}
}


void CSjTetris1Dlg::InitGuestData()
{
	for (int i = 1; i < USER_CNT; i++)
	{
		m_Guest[i].strName = " �� �� �� �� ";
		m_Guest[i].nScore = 0;
		m_Guest[i].cFlag = 'I';
		m_Guest[i].pClient = NULL;
	}
	m_Guest[0].strName = " �� ��   ";
	m_Guest[0].nScore = 0;
	m_nConnectCnt = 0;
}


void CSjTetris1Dlg::DisplayAllGuest()
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
	int i;
	for (i = 1; i < USER_CNT; i++)
	{
		DrawScr3((void*)m_Table[i], i, TRUE);
	}
}


void CSjTetris1Dlg::OnGameMode(UINT nID)
{
	// TODO: ���⿡ ���� �ڵ� �߰�.
}
